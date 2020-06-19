#include"MXpch.h"
#include"Application.h"

#include "Input.h"

namespace MatrixEngine
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
		:m_Running(true)
	{
		MX_ENGINE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		s_Window = Window::WindowCreate();
		s_Window->SetEventCallback(MX_BIND_EVENT_FN(Application::OnEvent));

		m_UILayer = new ImGuiLayer();
		PushSuperLayer(m_UILayer);
	}
	void Application::OnEvent(Event& event)
	{
		MX_ENGINE_TRACE("{0}", event);
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(MX_BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*(--it))->OnEvent(event);
			if (event.m_Handled) break;
		}
	}
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.2f, 0.2f, 0.2f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_UILayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_UILayer->End();

			s_Window->OnUpdate();
		}
	}
	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return false;
	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushSuperLayer(Layer* layer)
	{
		m_LayerStack.PushSuperLayer(layer);
		layer->OnAttach();
	}
}