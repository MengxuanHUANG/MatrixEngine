#pragma once
#include "MatrixEngine/RenderSystem/Renderer/Shader.h"
#include<glm/glm.hpp>

namespace MatrixEngine
{
	//TODO: Remove!
	typedef unsigned int GLenum;

	class OpenGLShader: public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		
		virtual void SetUniformInt(const std::string& name, int value) override;
		virtual void SetUniformMat4(const std::string& name, const glm::mat4& value) override;
		virtual void SetUniformFloat(const std::string& name, float value) override;
		virtual void SetUniformFloat3(const std::string& name, const glm::vec3& value) override;
		virtual void SetUniformFloat4(const std::string& name, const glm::vec4& value) override;

		virtual const std::string& GetName() const override { return m_Name; }

		void UploadUniformInt(const std::string& name, int value);

		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& value);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& value);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& value);

		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ReadFile(const std::string& filepath );
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& program);
		void Compile(std::unordered_map<GLenum, std::string>);
	private:
		uint32_t m_RendererID;
		std::string m_Name;
	};
}