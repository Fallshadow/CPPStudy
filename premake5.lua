workspace "CPPStudy"
    architecture "x64"
	targetdir "build"

    configurations 
	{ 
		"Debug", 
        "Release",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CPPStudy"
    location "CPPStudy"
    kind "ConsoleApp"
    language "C++"

    files 
	{ 
        "%{prj.name}/include/**.h", 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 
    }

    includedirs
	{
		"%{prj.name}/include",
        "%{prj.name}/src",
    }

    filter "configurations:Debug"
        defines "STUDY_DEBUG"
        symbols "On"
                
    filter "configurations:Release"
        defines "STUDY_RELEASE"
        optimize "On"