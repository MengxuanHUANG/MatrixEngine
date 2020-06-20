#pragma once
#include "MatrixEngine/RenderSystem/Camera/OrthographicCamera.h"
#include "MatrixEngine/RenderSystem/Buffers/VertexArray.h"
#include "Shader.h"

namespace MatrixEngine
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL
	};
	class Renderer
	{
	public:

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Init();
		static void ShutDown();
		
		static void OnWindowResize(uint32_t width, uint32_t height);
		static void Submit(const Ref<Shader> shader, const Ref<VertexArray>& vertexArray, const glm::mat4 transform = glm::mat4(1.0f));

		static void Shutdown();
		static void Flush();
		inline static RendererAPI GetAPI() { return s_SceneData.s_API; }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjMatrix;
			RendererAPI s_API = RendererAPI::OpenGL;
		};

		static SceneData s_SceneData;
	};
}