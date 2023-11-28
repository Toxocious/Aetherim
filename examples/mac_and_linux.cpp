#if defined( __APPLE__ ) || defined( __linux__ ) || defined( __FreeBSD__ ) || defined( __ANDROID__ )

#    include <iostream>
#    include <thread>
#    include <chrono>

#    include "src/wrapper.hpp"

void Init()
{
    printf( "[Aetherim] Initializing\n" );
    Il2cpp::initialize();
    printf( "[Aetherim] Initialization Complete\n\n" );

    printf( "[Aetherim] Dumping Images\n" );
    const auto Aetherim = std::make_unique<Wrapper>();
    printf( "[Aetherim] Images Dumped\n\n" );

    printf( "[Aetherim] Getting Assembly-CSharp Image\n" );
    const auto image = Aetherim->get_image( "Assembly-CSharp.dll" );
    printf( "\t[Aetherim] Assembly-CSharp -> %s (0x%zx)\n\n", image->get_name(), reinterpret_cast<uintptr_t>( image ) );

    printf( "[Aetherim] Getting PlayerHandler Class & Fields\n" );
    const auto player = image->get_class( "PlayerHandler" );
    printf( "\t[Aetherim] PlayerHandler -> %s (0x%zx)\n\n", player->get_name(), reinterpret_cast<uintptr_t>( player ) );

    for ( const auto field : player->get_fields() )
    {
        printf( "\t[Aetherim] PlayerHandler -> %s (0x%zx)\n", field->get_name(), field->get_offset() );
    }

    const auto player_instance = player->get_field( "Instance" )->get_as_static();
    if ( player_instance != nullptr )
        printf( "\t[Aetherim] PlayerHandler -> Static Instance (0x%zx)\n", reinterpret_cast<uintptr_t>( player_instance ) );

    std::this_thread::sleep_for( std::chrono::milliseconds( 60000 ) );
}

int main()
{
    printf( "[Aetherim] Initializing\n" );
    Il2cpp::initialize();
    printf( "[Aetherim] Initialization Complete\n\n" );

    printf( "[Aetherim] Dumping Images\n" );
    const auto Aetherim = std::make_unique<Wrapper>();
    printf( "[Aetherim] Images Dumped\n\n" );

    printf( "[Aetherim] Getting Assembly-CSharp Image\n" );
    const auto image = Aetherim->get_image( "Assembly-CSharp.dll" );
    printf( "\t[Aetherim] Assembly-CSharp -> %s (0x%zx)\n\n", image->get_name(), reinterpret_cast<uintptr_t>( image ) );

    printf( "[Aetherim] Getting PlayerHandler Class & Fields\n" );
    const auto player = image->get_class( "PlayerHandler" );
    printf( "\t[Aetherim] PlayerHandler -> %s (0x%zx)\n\n", player->get_name(), reinterpret_cast<uintptr_t>( player ) );

    for ( const auto field : player->get_fields() )
    {
        printf( "\t[Aetherim] PlayerHandler -> %s (0x%zx)\n", field->get_name(), field->get_offset() );
    }

    const auto player_instance = player->get_field( "Instance" )->get_as_static();
    if ( player_instance != nullptr )
        printf( "\t[Aetherim] PlayerHandler -> Static Instance (0x%zx)\n", reinterpret_cast<uintptr_t>( player_instance ) );

    std::this_thread::sleep_for( std::chrono::milliseconds( 60000 ) );

    return 0;
}

#endif
