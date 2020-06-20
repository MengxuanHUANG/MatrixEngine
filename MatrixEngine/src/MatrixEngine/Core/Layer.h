#pragma once

#include<string>
#include "MatrixEngine/Events/Event.h"
#include "Timestep.h"

namespace MatrixEngine
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep timestep) {}
		virtual void OnImGuiRender(float timestep) {}
		virtual void OnEvent(Event& event) {}
	protected:
		std::string m_Name;
	};
}