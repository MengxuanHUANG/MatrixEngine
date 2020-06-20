#include "MXpch.h"
#include "Buffer.h"

#include "../Renderer/Renderer.h"
#include "Platform/OpenGL/Buffer/OpenGLBuffer.h"

namespace MatrixEngine
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t sizes)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None :
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL :
			return CreateRef<OpenGLVertexBuffer>(vertices, sizes);
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* vertices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLIndexBuffer>(vertices, count);
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}