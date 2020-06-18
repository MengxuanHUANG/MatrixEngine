#pragma once
#include "Layer.h"

namespace MatrixEngine
{
	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushSuperLayer(Layer* layer);

		void PopLayer(Layer* layer);
		void PopSuperLayer(Layer* layer);

		std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }
		std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }
	private:
		unsigned int m_StackToptIndex = 0;
		std::vector<Layer*> m_LayerStack;
	};
}