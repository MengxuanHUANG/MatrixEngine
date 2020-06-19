#include"MXpch.h"
#include "GraphicsContext.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace MatrixEngine
{
	Scope<GraphicsContext> GraphicsContext::CreateContext(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    
			MX_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!"); 
			return nullptr;
		case RendererAPI::OpenGL:  
			return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}