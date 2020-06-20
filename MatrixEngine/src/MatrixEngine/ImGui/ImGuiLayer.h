#pragma once
#include "MatrixEngine/Core/Layer.h"

namespace MatrixEngine
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender(float timestep) override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}