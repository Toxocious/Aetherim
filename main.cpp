#include <iostream>

#include "src/wrapper.hpp"

DWORD WINAPI Init( HMODULE module )
{
  FILE * output;

  if ( AllocConsole() )
  {
    SetConsoleTitleA( "[Aetherim] Debug Console\n" );
    freopen_s( &output, "CONOUT$", "w", stdout );
  }

  printf( "[Aetherim] Initializing\n" );
  Il2cpp::initialize();
  printf( "[Aetherim] Initialization Complete\n\n" );

  printf( "[Aetherim] Dumping Images\n" );
  const auto Aetherim = std::make_unique<Wrapper>();
  printf( "[Aetherim] Images Dumped\n\n" );

  printf( "[Aetherim] Getting Assembly-CSharp Image\n" );
  const auto image = Aetherim->get_image( "Assembly-CSharp.dll" );
  printf( "\t[Aetherim] Assembly-CSharp -> %s (0x%Ix)\n\n", image->get_name(), reinterpret_cast<uintptr_t>( image ) );

  printf( "[Aetherim] Getting PlayerHandler Class & Fields\n" );
  const auto player = image->get_class( "PlayerHandler" );
  printf( "\t[Aetherim] PlayerHandler -> %s (0x%Ix)\n\n", player->get_name(), reinterpret_cast<uintptr_t>( player ) );

  for ( const auto field : static_cast<Class *>( player )->get_fields() )
  {
    const auto name = Il2cpp::get_field_name( field );

    printf( "\t[Aetherim] %s (0x%zx)\n", name, player->get_field(name)->get_offset() );
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
