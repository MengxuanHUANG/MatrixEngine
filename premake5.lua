workspace "MatrixEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sandbox"

--Include dirctories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MatrixEngine/vendor/GLFW/include"

include "MatrixEngine/vendor/GLFW"

project "MatrixEngine"
	location "MatrixEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "MXpch.h"
	pchsource "MatrixEngine/src/MXpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"MX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MX_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"MatrixEngine/src",
		"MatrixEngine/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MX_PLATFORM_WINDOWS"
		}

	links
	{
		"MatrixEngine"
	}

	filter "configurations:Debug"
		defines "MX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MX_DIST"
		runtime "Release"
		optimize "on"