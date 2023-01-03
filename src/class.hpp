#pragma once

#include <Windows.h>
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <vector>

#include "./api.hpp"

class Class
{
private:
  const char * name {};

public:
  Class() = default;

  using fields_t = std::vector<void *>;

  /**
   * Returns a pointer to the specified method.
   */
  auto get_method( const char * name ) const -> void *
  {
    auto method = il2cpp::get_method( this, name, -1 );
    if ( !method )
      return nullptr;

    return method;
  }

  /**
   * Returns a field given a name.
   */
  auto get_field( const char * name )
  {
    auto field = il2cpp::get_field( this, name );
    if ( !field )
      return nullptr;

    auto offset = il2cpp::get_field_offset( field );
    // auto type = il2cpp::get_field_type( field );

    // auto field_type = il2cpp::get_type_type( type );

    // return reinterpret_cast<field_type *>( this + offset );
  }

  /**
   * Returns all fields of the class as a vector of void pointers.
   */
  auto get_fields() const -> fields_t
  {
    fields_t m_fields {};
    if ( m_fields.size() )
      return m_fields;

    const size_t count = il2cpp::get_field_count( this );
    if ( count )
      m_fields.resize( count );

    void * iter = NULL;
    void * field = nullptr;

    size_t index = 0;

    while ( field = il2cpp::get_fields( this, &iter ) )
    {
      if ( !field || field == NULL )
        continue;

      m_fields[index++] = field;
    }

    return m_fields;
  }

  /**
   * Returns the offset of a field relative to the class.
   */
  auto get_field_offset( const char * name ) const -> size_t
  {
    const void * field = il2cpp::get_field( this, name );
    return il2cpp::get_field_offset( field );
  }

  /**
   * Returns a static field by name.
   */
  auto get_static_field( const char * name )
  {
    const auto field = il2cpp::get_field( this, "Instance" );

    void * val = NULL;

    il2cpp::get_static_field( field, &val );

    return val;
  }

  /**
   * Given a name, returns a class that's nested inside of the current class.
   */
  auto get_nested_class( const char * name ) const -> Class *
  {
    void * iter = NULL;

    while ( auto type = il2cpp::get_nested_types( this, &iter ) )
    {
      const auto class_name = il2cpp::get_class_name( type );

      if ( !strcmp( class_name, name ) )
        return type;
    }

    return nullptr;
  }

  /**
   * Return the name of the current class.
   */
  auto get_name() const -> const char * { return il2cpp::get_class_name( this ); }
};
