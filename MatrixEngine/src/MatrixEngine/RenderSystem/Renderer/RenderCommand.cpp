#include "MXpch.h"
#include "RenderCommand.h"

namespace MatrixEngine
{
	Scope<RenderAPI> RenderCommand::s_RenderAPI = RenderAPI::Create();
}