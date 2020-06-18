#pragma once
#include"Event.h"

namespace MatrixEngine
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y);

		std::string ToString() const override;

		inline float GetX() const { return m_Move.first; }
		inline float GetY()	const { return m_Move.second; }

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		std::pair<float, float> m_Move;
	};
	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}
		int m_Button;
	};
	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y);

		std::string ToString() const override;
		inline float GetOffsetX() const { return m_Offset.first; }
		inline float GetOffsetY() const { return m_Offset.second; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		std::pair<float, float> m_Offset;
	};
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button);

		std::string ToString()const override;

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button);

		std::string ToString()const override;

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
	
}