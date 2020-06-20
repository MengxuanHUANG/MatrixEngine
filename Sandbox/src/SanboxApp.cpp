#include "MatrixEngine.h"
#include "MatrixEngine/Core/EntryPoint.h"

#include "ExampleLayer.h"

class SandboxApp :public MatrixEngine::Application
{
public:
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
	}
	~SandboxApp()
	{

	}
};

MatrixEngine::Application* MatrixEngine::CreateApp()
{
	return new SandboxApp();
}