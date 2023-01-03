#pragma once

#include <cstdint>
#include <Windows.h>

#ifdef _WIN64
#  define APICALL __fastcall
#else
#  define APICALL __cdecl
#endif

class Class;
class Image;

namespace il2cpp
{
  inline bool initialized { false };

  // domain & assembly
  using get_thread_t = void *(APICALL *) ( void );
  using get_domain_t = void *(APICALL *) ( void );
  using get_assemblies_t = void **(APICALL *) ( const void * domain, size_t * count );

  inline get_thread_t get_thread = nullptr;
  inline get_domain_t get_domain = nullptr;
  inline get_assemblies_t get_assemblies = nullptr;

  // images
  using get_image_t = Image *(APICALL *) ( const void * assembly );
  using get_image_name_t = const char *(APICALL *) ( const void * image );
  using get_class_count_t = size_t( APICALL * )( const void * image );

  inline get_image_t get_image = nullptr;
  inline get_image_name_t get_image_name = nullptr;
  inline get_class_count_t get_class_count = nullptr;

  // objects
  using create_new_object_t = void *(APICALL *) ( void * domain, void * klass );

  inline create_new_object_t create_new_object = nullptr;

  // class
  using get_class_t = Class *(APICALL *) ( const void * image, const char * namespaze, const char * name );
  using get_class_name_t = const char *(APICALL *) ( const void * klass );
  using get_class_from_image_t = Class *(APICALL *) ( const void * image, size_t index );

  inline get_class_t get_class = nullptr;
  inline get_class_name_t get_class_name = nullptr;
  inline get_class_from_image_t get_class_from_image = nullptr;

  // types
  using get_nested_types_t = Class *(APICALL *) ( const void * klass, void * );
  using get_type_class_t = Class *(APICALL *) ( const void * type );
  using get_type_name_t = const char *(APICALL *) ( const void * type );
  using get_type_type_t = int( APICALL * )( void * type );

  inline get_nested_types_t get_nested_types = nullptr;
  inline get_type_class_t get_type_class = nullptr;
  inline get_type_name_t get_type_name = nullptr;
  inline get_type_type_t get_type_type = nullptr;

  // methods
  using get_method_t = void *(APICALL *) ( const void * klass, const char * name, int params );
  using get_methods_t = void *(APICALL *) ( const void * klass, void * iter );
  using get_method_param_count_t = int( APICALL * )( void * method );
  using get_method_param_name_t = const char *(APICALL *) ( void * method, int index );
  using get_method_return_type_t = void *(APICALL *) ( void * method );

  inline get_method_t get_method = nullptr;
  inline get_methods_t get_methods = nullptr;
  inline get_method_param_count_t get_method_param_count = nullptr;
  inline get_method_param_name_t get_method_param_name = nullptr;
  inline get_method_return_type_t get_method_return_type = nullptr;

  // fields
  using get_field_t = void *(APICALL *) ( const void * klass, const char * name );
  using get_field_offset_t = size_t( APICALL * )( const void * field );
  using get_field_count_t = size_t( APICALL * )( const void * klass );
  using get_fields_t = void *(APICALL *) ( const void * klass, void * iter );
  using get_field_name_t = const char *(APICALL *) ( const void * field );
  using get_field_type_t = void *(APICALL *) ( const void * field );
  using get_static_field_t = void *(APICALL *) ( const void * field, void * output );

  inline get_field_t get_field = nullptr;
  inline get_field_offset_t get_field_offset = nullptr;
  inline get_field_count_t get_field_count = nullptr;
  inline get_fields_t get_fields = nullptr;
  inline get_field_name_t get_field_name = nullptr;
  inline get_field_type_t get_field_type = nullptr;
  inline get_static_field_t get_static_field = nullptr;

  // strings
  using get_string_chars_t = wchar_t *(APICALL *) ( void * string_object );
  using create_new_string_t = const char *(APICALL *) ( void * domain, const char * text );

  inline get_string_chars_t get_string_chars = nullptr;
  inline create_new_string_t create_new_string = nullptr;

  /**
   * Initialize Unity's IL2CPP run-time methods.
   */
  inline void initialize()
  {
    if ( initialized )
      return;

    get_thread = reinterpret_cast<get_thread_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_thread_attach" ) );

    get_domain =
        reinterpret_cast<get_domain_t>( GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_domain_get" ) );

    get_assemblies = reinterpret_cast<get_assemblies_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_domain_get_assemblies" ) );

    get_image = reinterpret_cast<get_image_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_assembly_get_image" ) );

    get_image_name = reinterpret_cast<get_image_name_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_image_get_name" ) );

    get_class_from_image = reinterpret_cast<get_class_from_image_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_image_get_class" ) );

    get_class_count = reinterpret_cast<get_class_count_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_image_get_class_count" ) );

    get_class = reinterpret_cast<get_class_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_from_name" ) );

    get_class_name = reinterpret_cast<get_class_name_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_get_name" ) );

    get_methods = reinterpret_cast<get_methods_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_get_methods" ) );

    get_method = reinterpret_cast<get_method_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_get_method_from_name" ) );

    get_nested_types = reinterpret_cast<get_nested_types_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_get_nested_types" ) );

    get_field_count = reinterpret_cast<get_field_count_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_num_fields" ) );

    get_fields = reinterpret_cast<get_fields_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_get_fields" ) );

    get_field = reinterpret_cast<get_field_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_class_get_field_from_name" ) );

    get_field_offset = reinterpret_cast<get_field_offset_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_field_get_offset" ) );

    get_field_name = reinterpret_cast<get_field_name_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_field_get_name" ) );

    get_field_type = reinterpret_cast<get_field_type_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_field_get_type" ) );

    get_static_field = reinterpret_cast<get_static_field_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_field_static_get_value" ) );

    get_method_param_count = reinterpret_cast<get_method_param_count_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_method_get_param_count" ) );

    get_method_param_name = reinterpret_cast<get_method_param_name_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_method_get_param_name" ) );

    get_method_return_type = reinterpret_cast<get_method_return_type_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_method_get_return_type" ) );

    get_type_name = reinterpret_cast<get_type_name_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_type_get_name" ) );

    get_type_class = reinterpret_cast<get_type_class_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_type_get_class_or_element_class" ) );

    get_string_chars = reinterpret_cast<get_string_chars_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_string_chars" ) );

    create_new_string = reinterpret_cast<create_new_string_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_string_new" ) );

    create_new_object = reinterpret_cast<create_new_object_t>(
        GetProcAddress( GetModuleHandle( L"GameAssembly.dll" ), "il2cpp_object_new" ) );

    initialized = true;
  };
}
