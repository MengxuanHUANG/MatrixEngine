#include "MXpch.h"
#include "MouseEvents.h"

namespace MatrixEngine
{
	MouseMovedEvent::MouseMovedEvent(float x, float y)
		:m_Move(x,y)
	{}
	std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_Move.first << ", " << m_Move.second;
		return ss.str();
	}
	MouseScrolledEvent::MouseScrolledEvent(float x, float y)
		:m_Offset(x, y)
	{}
	std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << m_Offset.first << ", " << m_Offset.second;
		return ss.str();
	}
	MouseButtonPressedEvent::MouseButtonPressedEvent(int button)
		:MouseButtonEvent(button) 
	{}
	std::string MouseButtonPressedEvent::ToString()const
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
		return ss.str();
	}
	MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button)
		:MouseButtonEvent(button) 
	{}
	std::string MouseButtonReleasedEvent::ToString()const
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}
}