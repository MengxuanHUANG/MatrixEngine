#pragma once
#include "MatrixEngine/Core/Window.h"
#include <GLFW/glfw3.h>

namespace MatrixEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WinProps& props);
		~WindowsWindow();

		inline virtual bool IsVSync() const override { return m_Data.VSync; }
		inline virtual unsigned int GetWidth() const override { return m_Data.Width; }
		inline virtual unsigned int GetHeight() const override { return m_Data.Height; }
		inline virtual const std::string& GetTitle() const override { return m_Data.Title; }
		inline virtual void* GetNativeWindow() const override { return m_Window; }

		virtual void OnUpdate() override;
		virtual void SetVSync(bool enabled) override;
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

	private:
		void Init(const WinProps& props);
		void Shutdown();
	private:
		struct WindowData
		{
			unsigned int Width;
			unsigned int Height;
			std::string Title;
			EventCallbackFn EventCallback;
			bool VSync;
		};

		WindowData m_Data;
		GLFWwindow* m_Window;
	};
}