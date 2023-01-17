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
    auto method = Il2cpp::get_method( this, name, -1 );
    if ( !method )
      return nullptr;

    return method;
  }

  /**
   * Invoke a static method.
   */
  auto invoke_method( void * method_ptr, void ** params = nullptr ) -> void *
  {
    if ( method_ptr == nullptr )
      return nullptr;

    void * excption = nullptr;

    return Il2cpp::method_call( method_ptr, nullptr, params, &excption );
  }

  /**
   * Invoke a non-static mathod.
   * You need to pass a valid pointer to an Il2CppObject.
   */
  auto invoke_method( void * method_ptr, void * obj, void ** params = nullptr ) -> void *
  {
    if ( method_ptr == nullptr || obj == nullptr )
      return nullptr;

    void * excption = nullptr;

    return Il2cpp::method_call( method_ptr, obj, params, &excption );
  }

  /**
   * Returns a field given a name.
   */
  auto get_field( const char * name ) const -> void *
  {
    auto field = Il2cpp::get_field( this, name );
    if ( !field )
      return nullptr;

    return field;
  }

  /**
   * Returns all fields of the class as a vector of void pointers.
   */
  auto get_fields() const -> fields_t
  {
    fields_t m_fields {};
    if ( m_fields.size() )
      return m_fields;

    const size_t count = Il2cpp::get_field_count( this );
    if ( count )
      m_fields.resize( count );

    void * iter = NULL;
    void * field = nullptr;

    size_t index = 0;

    while ( field = Il2cpp::get_fields( this, &iter ) )
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
    const void * field = Il2cpp::get_field( this, name );
    return Il2cpp::get_field_offset( field );
  }

  /**
   * Given a name, returns a pointer to the static field.
   */
  auto get_static_field( const char * name )
  {
    const auto field = Il2cpp::get_field( this, name );

    void * val = NULL;

    Il2cpp::get_static_field( field, &val );

    return val;
  }

  /**
   * Given a name, returns a class that's nested inside of the current class.
   */
  auto get_nested_class( const char * name ) const -> Class *
  {
    void * iter = NULL;

    while ( auto type = Il2cpp::get_nested_types( this, &iter ) )
    {
      const auto class_name = Il2cpp::get_class_name( type );

      if ( !strcmp( class_name, name ) )
        return type;
    }

    return nullptr;
  }

  /**
   * Return the name of the current class.
   */
  auto get_name() const -> const char * { return Il2cpp::get_class_name( this ); }
};
