#include <iostream>

#include "src/dumper.hpp"

DWORD WINAPI Init( HMODULE module )
{
  FILE * output;

  if ( AllocConsole() )
  {
    SetConsoleTitleA( "[Aetherim] Debug Console\n" );
    freopen_s( &output, "CONOUT$", "w", stdout );
  }

  printf( "[Aetherim] Initializing\n" );
  il2cpp::initialize();
  printf( "[Aetherim] Initialization Complete\n\n" );

  printf( "[Aetherim] Dumping Images\n" );
  const auto Aetherim = std::make_unique<Dumper>();
  printf( "[Aetherim] Images Dumped\n\n" );

  printf( "[Aetherim] Getting Assembly-CSharp Image\n" );
  const auto image = Aetherim->get_image( "Assembly-CSharp.dll" );
  printf( "\t[Aetherim] Assembly-CSharp -> %s (0x%Ix)\n\n", image->get_name(), reinterpret_cast<uintptr_t>( image ) );

  printf( "[Aetherim] Getting PlayerHandler Class\n" );
  const auto player = image->get_class( "PlayerHandler" );
  printf( "\t[Aetherim] PlayerHandler -> %s (0x%Ix)\n\n", player->get_name(), reinterpret_cast<uintptr_t>( player ) );

  printf( "[Aetherim] Getting PlayerHandler Fields\n" );
  for ( const auto field : static_cast<Class *>( player )->get_fields() )
  {
    const auto name = il2cpp::get_field_name( field );
    printf( "\t[Aetherim] %s (0x%zx)\n", name, player->get_field_offset( name ) );
  }

  Sleep( 60000 );

  fclose( output );
  FreeConsole();
  FreeLibraryAndExitThread( module, 0 );

  return 0;
}

DWORD WINAPI DllMain( HINSTANCE module, DWORD reason, void * reserved )
{
  if ( reason != DLL_PROCESS_ATTACH )
    return FALSE;

  const auto thread = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE) Init, NULL, 0, NULL );
  if ( thread )
  {
    DisableThreadLibraryCalls( module );
    CloseHandle( thread );
  }

  return TRUE;
}
