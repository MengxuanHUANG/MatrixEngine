#pragma once

#ifdef MX_PLATFORM_WINDOWS

int main(char* argc, char** argv)
{
	MatrixEngine::Logger::Init();
	MX_ENGINE_WARN("Logging System Initialized!");

	auto app = MatrixEngine::CreateApp();
	app->Run();
	delete app;
}

#endif