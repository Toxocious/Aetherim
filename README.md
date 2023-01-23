<div align="center">
  <h1 align="center">Aetherim</h1>

  **Aetherim** is the source-code of an internal, injectable DLL that is used to access Unity's IL2CPP methods during run-time. I created this in order to learn more about C++ as well as Unity and how its IL2CPP run-time works.

  <img src="https://img.shields.io/github/issues/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <img src="https://img.shields.io/github/forks/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <img src="https://img.shields.io/github/stars/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <img src="https://img.shields.io/github/license/Toxocious/Aetherim?style=for-the-badge&logo=appveyor" />
  <a href="https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2FToxocious%Aetherim">
    <img src="https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2FToxocious%Aetherim&countColor=%2337d67a" />
  </a>
  <br /><br />

  Check us out on Discord and consider starring the repository if you liked it!

  <a href="https://discord.gg/Km6btPhs" target="_blank">
    <img src="https://discord.com/api/guilds/1002005327555862620/widget.png?style=banner2" alt="Discord Banner" />
  </a>
</div>
<br />



## Table of Contents
- [Table of Contents](#table-of-contents)
- [About The Project](#about-the-project)
  - [Tech Stack](#tech-stack)
  - [Dependencies](#dependencies)
- [Getting Started](#getting-started)
  - [Compiling As A DLL](#compiling-as-a-dll)
- [Usage In Existing Project](#usage-in-existing-project)
  - [Initialization](#initialization)
  - [Getting An Image/DLL](#getting-an-imagedll)
  - [Getting A Class](#getting-a-class)
  - [Getting A Static Field](#getting-a-static-field)
  - [Getting A Method Pointer](#getting-a-method-pointer)
  - [Invoking A Static Method](#invoking-a-static-method)
  - [Invoking A Non-Static Method](#invoking-a-non-static-method)
- [Contributing](#contributing)
  - [General Stance](#general-stance)
  - [Code Standards](#code-standards)
- [License](#license)



## About The Project
### Tech Stack
- C++
- Premake

### Dependencies
No dependencies are required.


## Getting Started
Premake is used to generate the files that are used to compile the code.

I developed this on Windows and used Premake5 to generate VS2022 solution files to compile.

I do not guarantee that this will compile any other way.

### Compiling As A DLL
1. Install Premake
2. Clone this repository
3. Open the project directory in your terminal
4. Run ``premake5 <TARGET>``
5. Open the project file in the appropriate software and compile the .dll


## Usage In Existing Project
Add the repository into your project (typically in a `/deps` folder or something).

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

### Initialization
Initialize the wrapper by calling the dumper constructor early on in your code.

```cpp
const auto Wrapper = std::make_unique<Wrapper>();
```

You now have access to the wrapper and the methods that it provides to you.

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

### Getting A Static Field
Static fields are great. They often provide a pointer to an instance of the class. We can easily get the pointer to a class's static field like so:

```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_handler = Asm_CSharp->get_class( "PlayerHandler" );
const auto get_player_instance = player_handler->get_field( "Instance" );
const auto player_instance = get_player_instance->get_static_value();
```

If found, a pointer is returned, otherwise `nullptr` is returned.

These methods may me chained if you don't need to use the initial class or field class for anything, like so:
```cpp
const auto Asm_CSharp = Wrapper->get_image( "Assembly-CSharp.dll" );
const auto player_instance = Asm_CSharp->get_class( "PlayerHandler" )->get_field( "Instance" )->get_static_value();
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
        get_player_position, // method pointer
        instance,            // instance/object pointer
        params               // either a void * of params or nullptr
      )
    );
}
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
