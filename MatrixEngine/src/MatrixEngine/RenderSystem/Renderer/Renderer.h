#pragma once

namespace MatrixEngine
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL
	};
	class Renderer
	{
	public:
		static void Init();
		static void ShutDown();
		inline static RendererAPI GetAPI() { return r_API; }
	private:
		static RendererAPI r_API;
	};
}