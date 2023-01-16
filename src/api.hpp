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

  // debugger
  using is_debugger_attached_t = bool( APICALL * )( void );

  inline is_debugger_attached_t is_debugger_attached = nullptr;

  // internal calls
  using add_icall_t = void( APICALL * )( const char * name, void * method_ptr );
  using resolve_icall_t = void *(APICALL *) ( const char * name );

  inline add_icall_t add_icall = nullptr;
  inline resolve_icall_t resolve_icall = nullptr;

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

  // arrays
  using get_array_element_size_t = int( APICALL * )( const void * array_class );
  using get_array_class_t = void *(APICALL *) ( const void * element_class, uint32_t rank );
  using get_array_length_t = uint32_t( APICALL * )( const void * array );
  using array_new_t = void *(APICALL *) ( void * element_type_infof, size_t length );

  inline get_array_element_size_t get_array_element_size = nullptr;
  inline get_array_class_t get_array_class = nullptr;
  inline get_array_length_t get_array_length = nullptr;
  inline array_new_t array_new = nullptr;

  // class
  using get_class_t = Class *(APICALL *) ( const void * image, const char * namespaze, const char * name );
  using get_class_name_t = const char *(APICALL *) ( const void * klass );
  using get_class_namespace_t = const char *(APICALL *) ( const void * klass );
  using get_class_from_image_t = Class *(APICALL *) ( const void * image, size_t index );
  using get_class_type_t = void *(APICALL *) ( const void * klass );
  using get_class_generic_t = bool( APICALL * )( const void * klass );
  using get_class_inflated_t = bool( APICALL * )( const void * klass );
  using get_class_has_parent_t = bool( APICALL * )( const void * klass, const void * klass_c );
  using get_class_get_parent_t = void *(APICALL *) ( const void * klass );
  using get_class_is_subclass_of_t = bool( APICALL * )( const void * klass,
                                                        const void * parent_class,
                                                        bool check_interfaces );
  using get_class_from_type_t = void *(APICALL *) ( const void * type );
  using get_class_event_info_t = void *(APICALL *) ( const void * klass, void * iter );
  using get_class_interfaces_t = void *(APICALL *) ( const void * klass, void * iter );
  using get_class_properties_t = void *(APICALL *) ( const void * klass, void * iter );
  using get_class_property_from_name_t = void *(APICALL *) ( const void * klass, const char * name );

  inline get_class_t get_class = nullptr;
  inline get_class_name_t get_class_name = nullptr;
  inline get_class_namespace_t get_class_namespace = nullptr;
  inline get_class_from_image_t get_class_from_image = nullptr;
  inline get_class_type_t get_class_type = nullptr;
  inline get_class_generic_t get_class_generic = nullptr;
  inline get_class_inflated_t get_class_inflated = nullptr;
  inline get_class_has_parent_t get_class_has_parent = nullptr;
  inline get_class_get_parent_t get_class_get_parent = nullptr;
  inline get_class_is_subclass_of_t get_class_is_subclass_of = nullptr;
  inline get_class_from_type_t get_class_from_type = nullptr;
  inline get_class_event_info_t get_class_event_info = nullptr;
  inline get_class_interfaces_t get_class_interfaces = nullptr;
  inline get_class_properties_t get_class_properties = nullptr;
  inline get_class_property_from_name_t get_class_property_from_name = nullptr;

  // types
  using get_nested_types_t = Class *(APICALL *) ( const void * klass, void * );
  using get_type_class_t = Class *(APICALL *) ( const void * type );
  using get_type_name_t = const char *(APICALL *) ( const void * type );
  using get_type_object_t = void *(APICALL *) ( const void * type );
  using get_type_type_t = int( APICALL * )( void * type );

  inline get_nested_types_t get_nested_types = nullptr;
  inline get_type_class_t get_type_class = nullptr;
  inline get_type_name_t get_type_name = nullptr;
  inline get_type_object_t get_type_object = nullptr;
  inline get_type_type_t get_type_type = nullptr;

  // methods
  using method_call_t = void *(APICALL *) ( void * method, void * obj, void ** params, void ** excption );
  using get_method_t = void *(APICALL *) ( const void * klass, const char * name, int params );
  using get_methods_t = void *(APICALL *) ( const void * klass, void * iter );
  using get_method_param_count_t = int( APICALL * )( void * method );
  using get_method_param_name_t = const char *(APICALL *) ( void * method, int index );
  using get_method_return_type_t = void *(APICALL *) ( void * method );

  inline method_call_t method_call = nullptr;
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
  using get_field_object_t = void *(APICALL *) ( const void * field, const void * obj );
  using get_field_type_t = void *(APICALL *) ( const void * field );
  using get_static_field_t = void *(APICALL *) ( const void * field, void * output );
  using set_static_field_t = void *(APICALL *) ( const void * field, void * value );

  inline get_field_t get_field = nullptr;
  inline get_field_offset_t get_field_offset = nullptr;
  inline get_field_count_t get_field_count = nullptr;
  inline get_fields_t get_fields = nullptr;
  inline get_field_name_t get_field_name = nullptr;
  inline get_field_object_t get_field_object = nullptr;
  inline get_field_type_t get_field_type = nullptr;
  inline get_static_field_t get_static_field = nullptr;
  inline set_static_field_t set_static_field = nullptr;

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

    const auto GameAssemblyHandle = GetModuleHandle( L"GameAssembly.dll" );

    is_debugger_attached =
        reinterpret_cast<is_debugger_attached_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_is_debugger_attached" ) );

    // Internal Calls
    add_icall = reinterpret_cast<add_icall_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_add_internal_call" ) );

    resolve_icall = reinterpret_cast<resolve_icall_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_resolve_icall" ) );

    // Thread
    get_thread = reinterpret_cast<get_thread_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_thread_attach" ) );

    // Domains & Assemblies
    get_domain = reinterpret_cast<get_domain_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_domain_get" ) );

    get_assemblies =
        reinterpret_cast<get_assemblies_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_domain_get_assemblies" ) );

    // Images
    get_image = reinterpret_cast<get_image_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_assembly_get_image" ) );

    get_image_name =
        reinterpret_cast<get_image_name_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_image_get_name" ) );

    get_class_from_image =
        reinterpret_cast<get_class_from_image_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_image_get_class" ) );

    get_class_count =
        reinterpret_cast<get_class_count_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_image_get_class_count" ) );

    // Objects
    create_new_object =
        reinterpret_cast<create_new_object_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_object_new" ) );

    // Arrays
    get_array_element_size =
        reinterpret_cast<get_array_element_size_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_array_element_size" ) );

    get_array_class =
        reinterpret_cast<get_array_class_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_array_class_get" ) );

    get_array_length =
        reinterpret_cast<get_array_length_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_array_length" ) );

    array_new = reinterpret_cast<array_new_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_array_new" ) );

    // Classes
    get_class = reinterpret_cast<get_class_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_from_name" ) );

    get_class_name =
        reinterpret_cast<get_class_name_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_name" ) );

    get_class_namespace =
        reinterpret_cast<get_class_namespace_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_namespace" ) );

    get_class_from_type = reinterpret_cast<get_class_from_type_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_class_from_il2cpp_type" ) );

    get_class_type =
        reinterpret_cast<get_class_type_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_enum_basetype" ) );

    get_class_generic =
        reinterpret_cast<get_class_generic_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_is_generic" ) );

    get_class_inflated =
        reinterpret_cast<get_class_inflated_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_is_inflated" ) );

    get_class_inflated =
        reinterpret_cast<get_class_inflated_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_is_inflated" ) );

    get_class_has_parent =
        reinterpret_cast<get_class_has_parent_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_has_parent" ) );

    get_class_get_parent =
        reinterpret_cast<get_class_get_parent_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_parent" ) );

    get_class_is_subclass_of = reinterpret_cast<get_class_is_subclass_of_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_class_is_subclass_of" ) );

    get_class_event_info =
        reinterpret_cast<get_class_event_info_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_events" ) );

    get_class_interfaces =
        reinterpret_cast<get_class_interfaces_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_interfaces" ) );

    get_class_properties =
        reinterpret_cast<get_class_properties_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_properties" ) );

    get_class_property_from_name = reinterpret_cast<get_class_property_from_name_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_property_from_name" ) );

    method_call = reinterpret_cast<method_call_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_runtime_invoke" ) );

    get_methods = reinterpret_cast<get_methods_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_methods" ) );

    get_method =
        reinterpret_cast<get_method_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_method_from_name" ) );

    get_nested_types =
        reinterpret_cast<get_nested_types_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_nested_types" ) );

    get_field_count =
        reinterpret_cast<get_field_count_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_num_fields" ) );

    get_fields = reinterpret_cast<get_fields_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_fields" ) );

    get_field =
        reinterpret_cast<get_field_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_class_get_field_from_name" ) );

    get_field_offset =
        reinterpret_cast<get_field_offset_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_field_get_offset" ) );

    get_field_name =
        reinterpret_cast<get_field_name_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_field_get_name" ) );

    get_field_object =
        reinterpret_cast<get_field_object_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_field_get_value_object" ) );

    get_field_type =
        reinterpret_cast<get_field_type_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_field_get_type" ) );

    get_static_field =
        reinterpret_cast<get_static_field_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_field_static_get_value" ) );

    set_static_field =
        reinterpret_cast<set_static_field_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_field_static_set_value" ) );

    get_method_param_count = reinterpret_cast<get_method_param_count_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_method_get_param_count" ) );

    get_method_param_name = reinterpret_cast<get_method_param_name_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_method_get_param_name" ) );

    get_method_return_type = reinterpret_cast<get_method_return_type_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_method_get_return_type" ) );

    get_type_object =
        reinterpret_cast<get_type_object_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_type_get_object" ) );

    get_type_name = reinterpret_cast<get_type_name_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_type_get_name" ) );

    get_type_class = reinterpret_cast<get_type_class_t>(
        GetProcAddress( GameAssemblyHandle, "il2cpp_type_get_class_or_element_class" ) );

    get_string_chars =
        reinterpret_cast<get_string_chars_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_string_chars" ) );

    create_new_string =
        reinterpret_cast<create_new_string_t>( GetProcAddress( GameAssemblyHandle, "il2cpp_string_new" ) );

    initialized = true;
  };
}
