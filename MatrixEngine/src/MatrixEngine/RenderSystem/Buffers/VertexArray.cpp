#include "MXpch.h"

#include "VertexArray.h"
#include "../Renderer/Renderer.h"

#include "Platform/OpenGL/Buffer/OpenGLVertexArray.h"

namespace MatrixEngine
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLVertexArray>();
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}