#pragma once

#include "MatrixEngine/RenderSystem/Buffers/VertexArray.h"
#include "MatrixEngine/RenderSystem/Camera/OrthographicCamera.h"
#include "MatrixEngine/RenderSystem/Texture/Texture.h"

#include "glm/glm.hpp"

namespace MatrixEngine
{
	class Renderer3D
	{
	public:
		static void Init();
		static void ShutDOwn();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		static void DrawCube(const glm::vec3& position, const glm::vec3& size, const glm::vec3& rotation, const glm::vec4& color);
		static void DrawCube(const glm::vec3& position, const glm::vec3& size, const glm::vec3& rotation, const Ref<Texture>& texture);
	private:
		inline static glm::mat4 GetTransform(const glm::vec3& position, const glm::vec3& size, const glm::vec3& rotation);
	};
}