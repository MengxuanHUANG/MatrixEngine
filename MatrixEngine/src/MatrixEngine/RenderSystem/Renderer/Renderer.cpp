#include "MXpch.h"
#include "Renderer.h"

namespace MatrixEngine
{
#ifdef MX_PLATFORM_WINDOWS
	RendererAPI Renderer::r_API = RendererAPI::OpenGL;
#endif
	void Renderer::Init()
	{
		switch (r_API)
		{
		case RendererAPI::OpenGL:
			break;
		default:
			MX_ENGINE_ASSERT(false, "Unkown RendererAPI!");
			break;
		}
		MX_ENGINE_WARN("Renderer Init!");
	}
	void Renderer::ShutDown()
	{
		MX_ENGINE_WARN("Renderer Shutdown!");
	}
}