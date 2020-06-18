#include "MXpch.h"
#include "ApplicationEvents.h"

namespace MatrixEngine
{
	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
		:m_Width(width), m_Height(height)
	{
	}
	std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResize: " << m_Width << ", " << m_Height;
		return ss.str();
	}
}