#include <iostream>

#include "src/dumper.hpp"
#include "./structs.h"

auto startup()
{
  if ( AllocConsole() )
  {
    SetConsoleTitleA( "[Aetherim] Debug Console\n" );

    FILE * output;
    freopen_s( &output, "CONOUT$", "w", stdout );

    return output;
  }
}

DWORD cleanup( HMODULE module, FILE * output )
{
  fclose( output );
  FreeConsole();
  FreeLibraryAndExitThread( module, 0 );

  return 0;
}

DWORD WINAPI Init( HMODULE module )
{
  auto output { startup() };

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

  printf( "\n[Aetherim] Getting PlayerHandler Instance\n" );
  const auto player_instance = player->get_static_field( "Instance" );
  if ( player_instance != nullptr )
  {
    printf( "\t[Aetherim] PlayerHandler Instance (0x%Ix)\n", reinterpret_cast<uintptr_t>( player_instance ) );

    const auto player = reinterpret_cast<PlayerHandler *>( player_instance );
    if ( player )
    {
      printf( "\t[Aetherim] PlayerHandler -> Current Steps: %i\n", player->fields.CurrentSteps );
      // printf( "\t[Aetherim] PlayerHandler -> Steps Till Encounter: %i\n", player->WildCounter );
      // printf( "\t[Aetherim] PlayerHandler -> Position (x,y): %f,%f\n", player->PosX, player->PosY );
    }
  }

  Sleep( 60000 );
  return cleanup( module, output );
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
