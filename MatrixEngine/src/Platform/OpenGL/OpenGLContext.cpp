#include "MXpch.h"
#include "OpenGLContext.h"

namespace MatrixEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		MX_ENGINE_ASSERT(windowHandle,"Handle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MX_ENGINE_ASSERT(status, "Failed to iniitalize Glad!");

		MX_ENGINE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		MX_ENGINE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		MX_ENGINE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}