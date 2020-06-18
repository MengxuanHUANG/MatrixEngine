#pragma once
#include"MXpch.h"
#include"LayerStack.h"

namespace MatrixEngine
{
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_LayerStack)
		{
			delete layer;
		}
	}
	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerStack.emplace(m_LayerStack.begin() + m_StackToptIndex,layer);
		m_StackToptIndex++;
	}
	void LayerStack::PushSuperLayer(Layer* layer)
	{
		m_LayerStack.emplace_back(layer);
	}
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
		if (it != m_LayerStack.end())
		{
			m_LayerStack.erase(it);
			--m_StackToptIndex;
		}
	}
	void LayerStack::PopSuperLayer(Layer* layer)
	{
		auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
		if (it != m_LayerStack.end())
		{
			m_LayerStack.erase(it);
		}
	}
}