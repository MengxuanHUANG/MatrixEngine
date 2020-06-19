#pragma once
#include "Core.h"

#include"Window.h"

#include "LayerStack.h"
#include "MatrixEngine/Events/Events.h"

#include "MatrixEngine/ImGui/ImGuiLayer.h"

namespace MatrixEngine
{
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

		inline static Application& GetApp() { return *s_Instance; }
		inline Window& GetWindow() { return *s_Window; }
	private:
		bool m_Running;
		Window* s_Window;
		LayerStack m_LayerStack;

		ImGuiLayer* m_UILayer;

		static Application* s_Instance;
	};

	Application* CreateApp();
}