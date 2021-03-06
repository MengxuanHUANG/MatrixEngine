#pragma once

#include "Event.h"

namespace MatrixEngine
{
	class KeyBoardEvent :public Event
	{
	public:
		inline int GetKeycode() const { return m_Keycode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyBoardEvent(int keycode)
			:m_Keycode(keycode) {}
		int m_Keycode;
	};

	class KeyPressedEvent :public KeyBoardEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount);

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString()const override;
		EVENT_CLASS_TYPE(KeyPressed);
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyBoardEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyBoardEvent(keycode) {}

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyBoardEvent
	{
	public:
		KeyTypedEvent(int keycode)
			:KeyBoardEvent(keycode) {}

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyTyped)
	};
}
