#pragma once

#include <glm/glm.hpp>

namespace MatrixEngine
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);
		void SetProjection(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec3& GetRotaion() const { return m_Rotation; }

		void SetPosition(const glm::vec3& position) 
		{ 
			m_Position = position; 
			ReCalculateViewMatrix();
		}
		void SetRotation(const glm::vec3& rotation)
		{ 
			m_Rotation = rotation; 
			ReCalculateViewMatrix();
		}

		

		const glm::mat4& GetProjMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjMatrix() const { return m_ViewProjMatrix; }

	private:
		void ReCalculateViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjMatrix;

		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
	};
}
