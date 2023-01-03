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
</div>



## Table of Contents
- [Table of Contents](#table-of-contents)
- [About The Project](#about-the-project)
  - [Screenshot](#screenshot)
  - [Tech Stack](#tech-stack)
  - [Dependencies](#dependencies)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
- [Contributing](#contributing)
  - [General Stance](#general-stance)
  - [Code Standards](#code-standards)
- [License](#license)



## About The Project
### Screenshot
[insert screenshot of it here or something]

### Tech Stack
- C++
- Premake

### Dependencies
No dependencies are required.


## Getting Started
Premake is used to generate the files that are used to compile the code.

I developed this on Windows and used Premake5 to generate VS2022 solution files to compile.

I do not guarantee that this will compile any other way.

### Prerequisites
1. Install Premake
2. Clone this repository
3. Open the project directory in your terminal
4. Run ``premake5 <TARGET>``
5. Open the project file in the appropriate software and compile the .dll



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
