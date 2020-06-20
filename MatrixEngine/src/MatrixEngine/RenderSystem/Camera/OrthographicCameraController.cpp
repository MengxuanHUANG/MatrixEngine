#include "MXpch.h"
#include "OrthographicCameraController.h"

#include "MatrixEngine/Core/Input.h"
#include "MatrixEngine/Core/Keycode.h"

namespace MatrixEngine
{
	OrthographicCameraController::OrthographicCameraController(float aspectRation, bool rotaionEnable)
		:m_AspectRatio(aspectRation), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotaionEnable)
	{
	}
	void OrthographicCameraController::OnUpdata(Timestep ts)
	{
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
		m_Camera.SetPostion(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;
	}
	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(MX_BIND_EVENT_FN(OrthographicCameraController::OnWindowResize));
	}
	OrthographicCamera& OrthographicCameraController::GetCamera()
	{
		return m_Camera;
	}
	const OrthographicCamera& OrthographicCameraController::GetCamera() const
	{
		return m_Camera;
	}
	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetOffsetY() * 0.5f;
		m_ZoomLevel = max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& e)
	{
		m_AspectRatio = (float)e.GetWidth() / (float) e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}