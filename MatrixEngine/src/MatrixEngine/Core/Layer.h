#pragma once

#include<string>
#include "MatrixEngine/Events/Event.h"

namespace MatrixEngine
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetch() {}
		virtual void OnUpdata() {}
		virtual void OnImGuiUpdate() {}
		virtual void OnEvent(Event& event) {}
	protected:
		std::string m_Name;
	};
}