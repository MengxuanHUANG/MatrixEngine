#pragma once
#include<string>
#include<memory>
#include<functional>

#include "Core.h"
#include "MatrixEngine/Events/Events.h"

namespace MatrixEngine
{
	struct WinProps
	{
		unsigned int Width;
		unsigned int Height;
		std::string Title;
		WinProps(
			unsigned int width = 2048, 
			unsigned int height = 1080, 
			const std::string& title = "Matrix Engine"
			)
			:Width(width), Height(height), Title(title)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual const std::string& GetTitle() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> WindowCreate(const WinProps& props = WinProps());
	};	
}