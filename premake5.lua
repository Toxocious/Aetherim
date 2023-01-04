workspace "Aetherim"
  architecture "x32"

  configurations { "Debug", "Release" }

  filter "configurations:Debug"
    Output_Dir = "Debug"

  filter "configurations:Release"
    Output_Dir = "Release"

  CPP_Version = "c++17"
  MSVC_Version = "v143"

  function Declare_MSVC_Options()
    filter "system:windows"
    floatingpoint "Fast"
    toolset(MSVC_Toolset)
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

    targetdir("bin/" .. Output_Dir .. "/")
    objdir("bin/" .. Output_Dir .. "/obj")

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
      flags { }
      editandcontinue "Off"
      defines { "DEBUG" }

    filter "configurations:Release"
      flags { "NoManifest" }
      defines { "RELEASE" }
      optimize "speed"
