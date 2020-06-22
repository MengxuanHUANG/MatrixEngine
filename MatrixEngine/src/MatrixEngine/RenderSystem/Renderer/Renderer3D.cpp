#include "MXpch.h"
#include "Renderer3D.h"

#include "RenderCommand.h"

#include "MatrixEngine/RenderSystem/Renderer/Shader.h"

#include<glm/gtc/matrix_transform.hpp>

namespace MatrixEngine
{
	struct Renderer3DStorage
	{
		Ref<VertexArray> VertexArray;
		Ref<Shader> Shader;
		Ref<Texture> WhiteTexture;
	};
	static Renderer3DStorage* s_Data;

	inline glm::mat4 Renderer3D::GetTransform(const glm::vec3& position, const glm::vec3& size, const glm::vec3& rotation)
	{
		if (rotation == glm::vec3(0.0f))
		{
			return glm::translate(glm::mat4(1.0f), position)
				* glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
		}
		else
		{
			return glm::translate(glm::mat4(1.0f), position)
				* glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), { 1.0f, 0.0f, 0.0f })
				* glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), { 0.0f, 1.0f, 0.0f })
				* glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), { 0.0f, 0.0f, 1.0f })
				* glm::scale(glm::mat4(1.0f), { size.x, size.y, size.z });
		}
	}

	void Renderer3D::Init()
	{
		s_Data = new Renderer3DStorage();

		float square[5 * 8] =
		{
			//Top
		    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f,
		    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			 0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			//Buttom
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			 0.5f, -0.5f, 0.5f, 1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 0.0f, 1.0f
		};

		s_Data->VertexArray = VertexArray::Create();
		Ref<VertexBuffer> squareVB;
		squareVB = MatrixEngine::VertexBuffer::Create(square, sizeof(square));

		BufferLayout layout = {
			{ ShaderDataType::Float3, "a_Position" },
			{ MatrixEngine::ShaderDataType::Float2, "a_TextCoord" }
		};
		squareVB->SetLayout(layout);
		s_Data->VertexArray->AddVertexBuffer(squareVB);

		uint32_t squareIndices[] = 
		{ 
			0, 1, 2, 2, 3, 0,//Top
			4, 5, 6, 6, 7, 4,//Buttom
			0, 1, 5, 5, 4, 0,//Left
			2, 6, 7, 7, 3, 2,//Right
			1, 2, 6, 6, 5, 1,//Front
			0, 4, 7, 7, 3, 0//Back
		};
		Ref<IndexBuffer> squareIB;
		squareIB = IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		s_Data->VertexArray->AddIndexBuffer(squareIB);

		uint32_t whiteTextureData = 0xffffffff;

		s_Data->WhiteTexture = Texture2D::Create(1, 1);
		s_Data->WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

		s_Data->Shader = Shader::Create("assets/shaders/Texture.glsl");
		s_Data->Shader->Bind();
		s_Data->Shader->SetUniformInt("u_Texture", 0);
	}
	void Renderer3D::ShutDOwn()
	{
		delete s_Data;
	}
	void Renderer3D::BeginScene(const OrthographicCamera& camera)
	{
		s_Data->Shader->Bind();
		s_Data->Shader->SetUniformMat4("u_ViewProjection", camera.GetViewProjMatrix());
	}
	void Renderer3D::EndScene()
	{
	}
	void Renderer3D::DrawCube(const glm::vec3& position, const glm::vec3& size, const glm::vec3& rotation, const glm::vec4& color)
	{
		s_Data->Shader->SetUniformFloat4("u_Color", color);
		s_Data->Shader->SetUniformFloat("u_TilingFactor", 1.0f);
		s_Data->WhiteTexture->Bind();

		s_Data->Shader->SetUniformMat4("u_Transform", GetTransform(position, size, rotation));

		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}

	void Renderer3D::DrawCube(const glm::vec3& position, const glm::vec3& size, const glm::vec3& rotation, const Ref<Texture>& texture)
	{
		s_Data->Shader->SetUniformFloat4("u_Color", glm::vec4(1.0f));
		s_Data->Shader->SetUniformFloat("u_TilingFactor", 1.0f);
		if (texture->IsDataLoad())
		{
			texture->Bind();
		}
		else
		{
			s_Data->WhiteTexture->Bind();
		}

		s_Data->Shader->SetUniformMat4("u_Transform", GetTransform(position, size, rotation));

		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}
}