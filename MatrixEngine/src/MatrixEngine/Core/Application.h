#pragma once
#include"Window.h"
#include "Core.h"
#include "LayerStack.h"

namespace MatrixEngine
{
	class Event;
	class WindowCloseEvent;

	class Application
	{
	public:
		Application();
		~Application() = default;

		void Run();
		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& event);

		void PushLayer(Layer* layer);
		void PushSuperLayer(Layer* layer);

		inline static Application* GetApplication() { return s_Instance; }

	private:
		bool m_Running;
		Scope<Window> s_Window;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApp();
}