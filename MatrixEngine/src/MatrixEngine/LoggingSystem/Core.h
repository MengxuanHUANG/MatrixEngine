#pragma once

#define MX_ENGINE_TRACE(...) ::MatrixEngine::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define MX_ENGINE_INFO(...)  ::MatrixEngine::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define MX_ENGINE_WARN(...)  ::MatrixEngine::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define MX_ENGINE_ERROR(...) ::MatrixEngine::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define MX_ENGINE_FATAL(...) ::MatrixEngine::Logger::GetEngineLogger()->fatal(__VA_ARGS__)

#define MX_CLIENT_TRACE(...) ::MatrixEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define MX_CLIENT_INFO(...)  ::MatrixEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define MX_CLIENT_WARN(...)  ::MatrixEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define MX_CLIENT_ERROR(...) ::MatrixEngine::Logger::GetClientLogger()->error(__VA_ARGS__)
#define MX_CLIENT_FATAL(...) ::MatrixEngine::Logger::GetClientLogger()->fatal(__VA_ARGS__)

#ifdef MX_DEBUG
#define MX_ENABLE_ASSERTS
#endif

#ifdef MX_ENABLE_ASSERTS
#define MX_CLIENT_ASSERT(x, ...) {if(!(x)) {MX_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#define MX_ENGINE_ASSERT(x, ...) {if(!(x)) {MX_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define MX_CLIENT_ASSERT(x, ...)
#define MX_ENGINE_ASSERT(x, ...)
#endif