#include "MXpch.h"
#include "KeyBoardEvents.h"

namespace MatrixEngine
{
	KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount)
		:KeyBoardEvent(keycode), m_RepeatCount(repeatCount)
	{
	}

	std::string KeyPressedEvent::ToString()const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_Keycode << ", " << m_RepeatCount;
		return ss.str();
	}
	std::string KeyReleasedEvent::ToString()const
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_Keycode;
		return ss.str();
	}
	std::string KeyTypedEvent::ToString()const
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_Keycode;
		return ss.str();
	}
}