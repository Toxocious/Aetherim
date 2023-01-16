#pragma once

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

#include "./image.hpp"

class Wrapper
{
public:
  using images_t = std::vector<Image *>;

private:
  images_t m_images {};

public:
  /**
   * Dumps all images.
   */
  Wrapper()
  {
    size_t count = 0U;

    const auto domain = il2cpp::get_domain();
    const auto assemblies = il2cpp::get_assemblies( domain, &count );

    for ( size_t index = 0U; index < count; ++index )
    {
      auto image = il2cpp::get_image( assemblies[index] );
      if ( image )
        m_images.emplace_back( static_cast<Image *>( image ) );
    }
  }

  /**
   * Returns a pointer to the desired image if found.
   */
  auto get_image( const char * name ) const -> Image *
  {
    for ( const auto image : m_images )
    {
      if ( !strcmp( name, image->get_name() ) )
        return image;
    }

    return nullptr;
  }

  /**
   * Returns all images.
   */
  auto get_images() const -> images_t { return m_images; }
};
