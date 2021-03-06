#pragma once
#include <GLFW/glfw3.h>

#include "MatrixEngine/RenderSystem/Renderer/GraphicsContext.h"

namespace MatrixEngine
{
	class OpenGLContext :public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}