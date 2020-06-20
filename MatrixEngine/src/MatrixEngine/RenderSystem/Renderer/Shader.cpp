#include "MXpch.h"

#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace MatrixEngine
{
	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL:
			return std::make_shared<OpenGLShader>(filepath);
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MX_ENGINE_ASSERT(false, "RendererAPI::None is not support!");
			return nullptr;
		case RendererAPI::OpenGL:
			return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		default:
			break;
		}
		MX_ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	void ShaderLib::Add(const std::string& name, const Ref<Shader>& shader)
	{
		MX_ENGINE_ASSERT(!Exists(name), "Shader already exists!");
		m_Shaders[name] = shader;
	}
	void ShaderLib::Add(const Ref<Shader>& shader)
	{
		std::string name = shader->GetName();
		Add(name, shader);
	}
	Ref<Shader> ShaderLib::Load(const std::string& filePath)
	{
		auto shader = Shader::Create(filePath);
		Add(shader);
		return shader;
	}
	Ref<Shader> ShaderLib::Load(const std::string& name, const std::string& filePath)
	{
		auto shader = Shader::Create(filePath);
		Add(name, shader);
		return shader;
	}
	Ref<Shader> ShaderLib::Get(const std::string& name)
	{
		MX_ENGINE_ASSERT(Exists(name), "Shader already exists!");
		return m_Shaders[name];
	}
	bool ShaderLib::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}