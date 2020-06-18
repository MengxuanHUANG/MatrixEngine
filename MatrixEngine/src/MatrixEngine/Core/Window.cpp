#pragma once
#include "MXpch.h"
#include "Window.h"

#include "Platform/Windows/WindowsWindow.h"

namespace MatrixEngine
{
	static bool IsWindowCreated = false;

#ifdef  MX_PLATFORM_WINDOWS
	Scope<Window> Window::WindowCreate(const WinProps& props)
	{
		MX_ENGINE_ASSERT(!IsWindowCreated, "Window already exists!");
		IsWindowCreated = true;
		return CreateScope<WindowsWindow>(props);
	}
#endif
}