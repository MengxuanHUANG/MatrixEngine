#include "MXpch.h"
#include "Texture.h"

#include "MatrixEngine/RenderSystem/Renderer/Renderer.h"
#include "Platform/OpenGL/Texture/OpenGLTexture.h"

namespace MatrixEngine
{
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLTexture2D>(width, height);
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}