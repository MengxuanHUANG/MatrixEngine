#include "MXpch.h"

#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace MatrixEngine
{
	Scope<RenderAPI> RenderAPI::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    
			MX_ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!"); 
			return nullptr;
		case RendererAPI::OpenGL:  
			return CreateScope<OpenGLRenderAPI>();
		}

		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}