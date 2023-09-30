<div align="center">
  <h1 align="center">Aetherim</h1>

  **Aetherim** is the source-code of a shared library that is used to access Unity's IL2CPP methods during run-time. Aetherim should work in both 64-bit and 32-bit programs, as well as on Linux, MacOS, and Windows.

  I created this in order to learn more about C++ as well as Unity and how its IL2CPP run-time works.

  <img src="https://img.shields.io/github/issues/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <img src="https://img.shields.io/github/forks/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <img src="https://img.shields.io/github/stars/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <br />
  <img src="https://img.shields.io/github/license/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <a href="https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2FToxocious%Aetherim">
    <img src="https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2FToxocious%Aetherim&countColor=%2337d67a" />
  </a>
  <br /><br />

  Check us out on Discord and consider starring the repository if you liked it!

  <a href="https://discord.gg/NRZ2zWfpwK" target="_blank">
    <img src="https://discord.com/api/guilds/1002005327555862620/widget.png?style=banner2" alt="Discord Banner" />
  </a>
</div>
<br />



## Table of Contents
- [Table of Contents](#table-of-contents)
- [Getting Started](#getting-started)
  - [Compiling The Library](#compiling-the-library)
    - [Linux and MacOS](#linux-and-macos)
    - [Windows](#windows)
- [Usage In Existing Project](#usage-in-existing-project)
  - [Basic Wrapper Examples](#basic-wrapper-examples)
  - [Initialization](#initialization)
  - [Getting An Image/DLL](#getting-an-imagedll)
  - [Getting A Class](#getting-a-class)
  - [Getting All Fields Of A Class](#getting-all-fields-of-a-class)
  - [Getting A Static Field](#getting-a-static-field)
  - [Getting A Field's Attribute](#getting-a-fields-attribute)
  - [Getting A Method Pointer](#getting-a-method-pointer)
  - [Invoking A Static Method](#invoking-a-static-method)
  - [Invoking A Non-Static Method](#invoking-a-non-static-method)
  - [Check If A Debugger Is Attached To The Thread](#check-if-a-debugger-is-attached-to-the-thread)
- [Contributing](#contributing)
  - [General Stance](#general-stance)
  - [Code Standards](#code-standards)
- [License](#license)



## Getting Started
Depending on the operating system that you're using, there's a handful of things to be aware of.

Linux and MacOS users have the best ease-of-use and can just run the compile script.

Windows users have a variety of options, all of which require additional tooling to compile the library.

### Compiling The Library
There is an included script ([./compile.sh](`compile.sh`)) that should be used to compile the library.

#### Linux and MacOS
You should be able to simply run the script and the library will be compiled.

#### Windows
A few different options are open for you.

1. Install [Visual Studio](https://visualstudio.microsoft.com/) and compile through it.
2. Install [Premake](https://premake.github.io/) and generate a project file, open the project file in the appropriate software, and compile that way.
3. Install [MinGW](https://www.msys2.org/) and [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) and run the [./compile.sh](`compile.sh`) script.

> Options 1 and 2 have been tested and are confirmed to work; option 3 has not been tested, but should work.

> If you haven't used Linux before or want the most user-friendly method of compilation, I recommend compiling through Visual Studio.



## Usage In Existing Project
Add the repository into your project (typically in a `/submodules` folder or something).

> Consider adding this repository as a git submodule, so that you can update your project easily when Aetherim updates.

```sh
git submodule add https://github.com/Toxocious/Aetherim
```

When Aetherim has updated, you can quickly pull the up-to-date code into your project and continue developing with Aetherim's updated functionality.

Use the following command to pull the up-to-date code into your project.

```sh
git submodule update --remote Aetherim
```

If you would like to remove Aetherim from your project, run the following command and the filetree for Aetherim and its submodule entry in your .gitmodules file will be removed.

```sh
git rm <path-to-Aetherim>
```

### Basic Wrapper Examples
Included are some very basic examples of how to use this library, all of which can be found in the [./examples](examples/) directory.

**Windows** [example file](examples/windows.cpp)
**Linux** [example file](examples/linux.cpp)
**Mac** [example file](examples/mac.cpp)

> As of the most recent update, there is no Linux or Mac example files.


### Initialization
Be sure to ``#include`` the ``Aetherim/src/wrapper.hpp`` file to your main entrypoint file so that you can access and initialize the IL2CPP wrapper.

Initialize the wrapper by calling the dumper constructor early on in your code.

```cpp
const auto Wrapper = std::make_unique<Wrapper>();
```

You now have access to the wrapper and the methods that it provides to you.

> The wrapper, upon initialization, automatically gets the IL2CPP domain and attaches it to the thread.
>
> This is necessary in order to prevent some access violation crashes.

### Getting An Image/DLL
Getting an IL2CPP image will provide you access to all classes that it holds, and helper methods to access things within the Image. These images are easily found by dropping a dumped game's files into something like DnSpy.

Get a pointer to an IL2CPP image like so:

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
```

If found, a pointer is returned, otherwise `nullptr` is returned.

### Getting A Class
After getting an IL2CPP image, you are granted access to any of its classes. You may get a pointer to the class by calling the line below, provided the name of the class that you're looking for.

In this example, we'll get the PlayerHandler class.

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
```

If found, a pointer is returned, otherwise `nullptr` is returned.

From here, PlayerHandler can provide you with various helper methods that allow you to get field and method pointers for fields and methods of the PlayerHandler class, as well as a helper method to invoke methods of the class.

### Getting All Fields Of A Class
Aetherim provides an easy way to get every field that a class has.

In the example below, we get all fields of the PlayerHandler class, and print out each field's attribute, name, and offset.

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto player = image->get_class( "PlayerHandler" );

for ( const auto field : player->get_fields() )
{
  const auto field_attribute = field->get_attribute();

  if ( field_attribute != nullptr )
    printf( "\t[Aetherim] PlayerHandler -> %s %s (0x%zx)\n", field_attribute, field->get_name(), field->get_offset() );
  else
    printf( "\t[Aetherim] PlayerHandler -> %s (0x%zx)\n", field->get_name(), field->get_offset() );
}
```

### Getting A Static Field
Static fields are great. They often provide a pointer to an instance of the class. We can easily get the pointer to a class's static field like so:

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto get_player_instance = player_handler->get_field( "Instance" )->get_as_static();
```

If found, a pointer is returned, otherwise `nullptr` is returned.

These methods may me chained if you don't need to use the initial class or field class for anything, like so:
```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_instance = Asm_CSharp->get_class( "PlayerHandler" )->get_field( "Instance" )->get_as_static();
```

### Getting A Field's Attribute
Getting a field's attribute tells you a lot about the field itself and how you can get or use it later.

This has multiple purposes, but the first two that come to mind is using it for SDK generation (to be implemented later on) or to get a field based on its attribute.

**What does this mean?** The latter will eventually allow Aetherim to fetch a given field through ``class->get_field()`` instead of through both ``class->get_field()`` and ``class->get_field()->as_static()``, since static fields lie in a different area in memory than non-static fields.

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto get_player_instance_attribute = player_handler->get_field( "Instance" )->get_attribute();
```



### Getting A Method Pointer
Methods are great, and allow us to do all sorts of things, from hooking based on the returned address, or even invoking the method with whatever parameters we want.

We can get the pointer of a method like so:

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto player_position = player_handler->get_method( "get_position" );
```

If found, a pointer is returned, otherwise `nullptr` is returned.

### Invoking A Static Method
Invoking a static method is easy. You only need a valid method pointer &mdash; no instance or object pointer is required.

You can invoke a static method like so:

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto player_instance = player_handler->get_method( "get_instance" );

if ( player_instance != nullptr )
{
  void * params = nullptr;

  const auto new_instance =
    reinterpret_cast<void *>(
      player_instance->invoke_static( params )
    );
};
```

### Invoking A Non-Static Method
Invoking a non-static method is easy, but can be tricky if you find yourself unable to get a proper instance/object pointer.

You can invoke a non-static method like so:

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto get_player_position = player_handler->get_method( "get_position" );

if ( get_player_position != nullptr )
{
  const auto instance = player_handler->get_field( "Instance" )->get_static_value();

  void * params = nullptr;

  const auto position =
    reinterpret_cast<Vector3 *>(
      get_player_position->invoke(
        instance, // instance/object pointer
        params    // either a void * of params or nullptr
      )
    );
}
```

### Check If A Debugger Is Attached To The Thread
Very basic. Returns a boolean indicating if a debugger is attached to the thread.

```cpp
const auto Wrapper = std::make_unique<Wrapper>();
const auto is_debugger_active = Wrapper->is_debugger_attached();
```



## Contributing
### General Stance
In general, we welcome pull requests that fix bugs or builds upon an existing feature.

1. Fork the Project
2. Create your Feature Branch (``git checkout -b feature/feature-name``)
3. Commit your Changes (``git commit -m 'Add some feature-name'``)
4. Push to the Branch (``git push origin feature/feature-name``)
5. Open a Pull Request

### Code Standards
There is a dedicated Clang configuration for this repository that will style all code to the required spec of the code-base.

Keep it clean.



## License
This project is licensed under GNU GPL 3.

For more information about the license, check out the [LICENSE](LICENSE).
