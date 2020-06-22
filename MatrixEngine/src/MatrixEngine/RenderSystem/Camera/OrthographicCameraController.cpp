#include "MXpch.h"
#include "OrthographicCameraController.h"

#include "MatrixEngine/Core/Input.h"
#include "MatrixEngine/Core/Keycode.h"
#include "MatrixEngine/Core/MouseButton.h"

namespace MatrixEngine
{
	OrthographicCameraController::OrthographicCameraController(float aspectRation, bool rotaionEnable)
		:m_AspectRatio(aspectRation), 
		m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), 
		m_Rotation(rotaionEnable),
		m_PreMousePos({0, 0})
	{
	}
	void OrthographicCameraController::OnUpdata(Timestep ts, glm::vec3& position, glm::vec3& rotation)
	{
		
		position = m_CameraPosition;
		rotation = m_CameraRotation;

		//Move the Camera
		if (Input::IsKeyPressed(MX_KEY_A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		else if (Input::IsKeyPressed(MX_KEY_D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		if (Input::IsKeyPressed(MX_KEY_W))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		else if (MatrixEngine::Input::IsKeyPressed(MX_KEY_S))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;

		//Rotate the Camera
		if (m_Rotation)
		{
			if (Input::IsKeyPressed(MX_KEY_Q))
				m_CameraRotation += m_CameraRotatedSpeed * ts;
			if (Input::IsKeyPressed(MX_KEY_E))
				m_CameraRotation -= m_CameraRotatedSpeed * ts;

			m_Camera.SetRotation(m_CameraRotation);
		}
		m_Camera.SetPosition(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;

		timestep = ts;
	}
	void OrthographicCameraController::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseScrolledEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::OnWindowResize));

		dispatcher.Dispatch<MouseButtonPressedEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::OnMouseButtonReleased));

		if (Input::IsKeyPressed(MX_KEY_LEFT_CONTROL) || Input::IsKeyPressed(MX_KEY_RIGHT_CONTROL))
		{
			if (Input::IsMouseButtonPressed(MX_MOUSE_BUTTON_LEFT))
				dispatcher.Dispatch<MouseMovedEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::CameraMoved));
		}
		else if (Input::IsMouseButtonPressed(MX_MOUSE_BUTTON_LEFT))
		{
			dispatcher.Dispatch<MouseMovedEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::CameraRotated));
		}
		else
		{
			m_PreMousePos = Input::GetMousePos();
		}
	}
	OrthographicCamera& OrthographicCameraController::GetCamera()
	{
		return m_Camera;
	}
	const OrthographicCamera& OrthographicCameraController::GetCamera() const
	{
		return m_Camera;
	}
	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& event)
	{
		m_ZoomLevel -= event.GetOffsetY() * 0.5f;
		m_ZoomLevel = max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& event)
	{
		m_AspectRatio = (float)event.GetWidth() / (float)event.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	bool OrthographicCameraController::OnMouseMoved(MouseMovedEvent& event)
	{
		m_PreMousePos = { event.GetX(), event.GetY() };
		return false;
	}
	bool OrthographicCameraController::OnMouseButtonPressed(MouseButtonPressedEvent& event)
	{
		return false;
	}
	bool OrthographicCameraController::OnMouseButtonReleased(MouseButtonReleasedEvent& event)
	{
		return false;
	}
	bool OrthographicCameraController::CameraRotated(MouseMovedEvent& event)
	{
		float deltaX = event.GetX() - m_PreMousePos.first;
		float deltaY = event.GetY() - m_PreMousePos.second;

		m_CameraRotation.x -= deltaX * m_CameraRotatedSpeed * timestep * 0.005f;
		m_CameraRotation.y -= deltaY * m_CameraRotatedSpeed * timestep * 0.005f;

		return false;
	}

	bool OrthographicCameraController::CameraMoved(MouseMovedEvent& event)
	{
		float deltaX = event.GetX() - m_PreMousePos.first;
		float deltaY = event.GetY() - m_PreMousePos.second;

		m_CameraPosition.x -= deltaX * m_CameraTranslationSpeed * timestep * 0.005;
		m_CameraPosition.y -= deltaY * m_CameraTranslationSpeed * timestep * 0.005;

		return false;
	}
}