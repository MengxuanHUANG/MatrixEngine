#pragma once

#include "MatrixEngine/Core/Core.h"

namespace MatrixEngine
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static Scope<GraphicsContext> CreateContext(void* window);
	};
}