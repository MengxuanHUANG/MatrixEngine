#pragma once

#include "MatrixEngine.h"

class ExampleLayer :public MatrixEngine::Layer
{
public:
	ExampleLayer(std::string Name)
		:Layer(Name)
	{

	}
	void OnAttach()
	{
		MX_CLIENT_WARN("{0} Attach!", m_Name);
	}
	void OnDetch() 
	{
	}
	void OnEvent(MatrixEngine::Event& event)
	{
	}
	void OnUpdata() 
	{
	}
	void OnImGuiUpdate() 
	{
	}
};