#pragma once

#include <Windows.h>
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <vector>

#include "./api.hpp"

class Field
{
public:
  Field() = default;

  /**
   * Return a static field given a name.
   */
  auto get_as_static() const -> void *
  {
    if ( Il2cpp::get_static_field == nullptr )
      return nullptr;

    void * val = NULL;

    Il2cpp::get_static_field( this, &val );

    return val;
  }

  /**
   * Sets the value of a static field.
   */
  auto set_static_value( void * value ) const -> void *
  {
    if ( Il2cpp::set_static_field == nullptr )
      return nullptr;

    return Il2cpp::set_static_field( this, value );
  }

  /**
   * Returns the offset of a field relative to the class.
   */
  auto get_offset() const -> size_t
  {
    if ( Il2cpp::get_field_offset == nullptr )
      return 0x0;

    return Il2cpp::get_field_offset( this );
  }

  /**
   * Returns an object pointer of the field.
   */
  auto get_object( const void * obj ) const -> void *
  {
    if ( Il2cpp::get_field_object == nullptr )
      return nullptr;

    return Il2cpp::get_field_object( this, obj );
  }

  /**
   * Returns a pointer to the data type of the field.
   */
  auto get_type() const -> void *
  {
    if ( Il2cpp::get_field_type == nullptr )
      return nullptr;

    return Il2cpp::get_field_type( this );
  }

  /**
   * @brief Get the field name.
   */
  auto get_name() const -> const char *
  {
    if ( Il2cpp::get_field_name == nullptr )
      return "Field->get_name() is nullptr";

    return Il2cpp::get_field_name( this );
  }
};
