workspace "Aetherim"
  architecture "x32"

  configurations { "Debug", "Release" }

  CPP_Version = "c++17"
  MSVC_Version = "v143"

  function Declare_MSVC_Options()
    filter "system:windows"
    floatingpoint "Fast"
    toolset(MSVC_Version)
    cppdialect(CPP_Version)

    disablewarnings { "4996" }
  end

  project "Aetherim"
    location "src"
    kind "SharedLib"
    language "C++"
    targetprefix ""
    targetname "aetherim"
    targetextension ".dll"

    Declare_MSVC_Options()

    files {
      "src/*.h",
      "src/**/*.h",
      "src/*.cpp",
      "src/**/*.cpp",
      "src/*.hpp",
      "src/**/*.hpp",

      "structs.h",
      "main.cpp",
    }

    flags {
      "LinkTimeOptimization",
      "MultiProcessorCompile"
    }

    filter "configurations:Debug"
      targetdir "bin/debug"
      objdir "bin/debug/obj"
      flags { }
      defines { "DEBUG" }
      editandcontinue "Off"

    filter "configurations:Release"
      targetdir "bin/release"
      objdir "bin/release/obj"
      flags { "NoManifest" }
      defines { "RELEASE" }
      optimize "speed"
