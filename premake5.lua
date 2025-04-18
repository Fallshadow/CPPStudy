workspace "CPPStudy"
    configurations 
	{ 
		"Debug", 
        "Release",
    }

project "CPPStudy"

    kind "ConsoleApp"

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