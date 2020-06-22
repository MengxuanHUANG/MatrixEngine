#pragma once
#include "OrthographicCamera.h"

#include "MatrixEngine/Events/Events.h"
#include "MatrixEngine/Core/Timestep.h"

namespace MatrixEngine
{
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRation, bool rotaionEnable);

		void OnUpdata(Timestep ts, glm::vec3& position, glm::vec3& rotation);
		void OnEvent(Event& event);

		OrthographicCamera& GetCamera();
		const OrthographicCamera& GetCamera() const;

		void SetZoomLevel(float level) { m_ZoomLevel = level; }
		float GetZoomLevel() const { return m_ZoomLevel; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnMouseMoved(MouseMovedEvent& event);

		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);
		bool CameraRotated(MouseMovedEvent& event);
		bool CameraMoved(MouseMovedEvent& event);

	private:
		float timestep;

		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation = false;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_CameraRotation = { 0.0f, 0.0f, 0.0f };

		float m_CameraTranslationSpeed = 5.0f, m_CameraRotatedSpeed = 180.0f;

		std::pair<float, float> m_PreMousePos;
	};
}