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
IncludeDir["GLFW"]	= "MatrixEngine/vendor/GLFW/include"
IncludeDir["Glad"]	= "MatrixEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "MatrixEngine/vendor/imgui"
IncludeDir["glm"]	= "MatrixEngine/vendor/glm"
IncludeDir["stb_image"] = "MatrixEngine/vendor/stb_image"

include "MatrixEngine/vendor/GLFW"
include "MatrixEngine/vendor/Glad"
include "MatrixEngine/vendor/imgui"

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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/glm/glm/**.h"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib",
		"ImGui"
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
		"MatrixEngine/vendor/spdlog/include",
		"MatrixEngine/vendor/GLFW/include",
		"MatrixEngine/vendor/Glad/include",
		"MatrixEngine/vendor",
		"%{IncludeDir.glm}"
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