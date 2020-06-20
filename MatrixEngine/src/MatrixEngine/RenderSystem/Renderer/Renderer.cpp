#include "MXpch.h"
#include "Renderer.h"

#include "RenderCommand.h"
#include "Renderer2D.h"

namespace MatrixEngine
{
	static bool RendererInited = false;
	Renderer::SceneData Renderer::s_SceneData;
	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		s_SceneData.ViewProjMatrix = camera.GetViewProjMatrix();
	}
	void Renderer::EndScene()
	{
	}
	void Renderer::Init()
	{
		MX_ENGINE_ASSERT(!RendererInited, "Renderer already exists!");
		RenderCommand::Init();
		Renderer2D::Init();
		RendererInited = true;
	}
	void Renderer::ShutDown()
	{
		MX_ENGINE_WARN("Renderer Shutdown!");
	}
	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}
	void Renderer::Submit(const Ref<Shader> shader, const Ref<VertexArray>& vertexArray, const glm::mat4 transform)
	{
		shader->Bind();
		shader->SetUniformMat4("u_ViewProjection", s_SceneData.ViewProjMatrix);
		shader->SetUniformMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
	void Renderer::Shutdown()
	{
	}
	void Renderer::Flush()
	{
	}
}