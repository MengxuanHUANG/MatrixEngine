#include "MXpch.h"
#include "Logger.h"
#include<spdlog/sinks/stdout_color_sinks.h>

namespace MatrixEngine
{
	static bool m_LoggerInited = false;

	std::shared_ptr<spdlog::logger> Logger::m_EngineLogger;
	std::shared_ptr<spdlog::logger> Logger::m_ClientLogger;
	void Logger::Init(const std::string& format )
	{
		MX_ENGINE_ASSERT(!m_LoggerInited, "Logger is already exists");

		spdlog::set_pattern(format);
		m_EngineLogger = spdlog::stdout_color_mt("MatrixEngine");
		m_EngineLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("APP");
		m_ClientLogger->set_level(spdlog::level::trace);

		m_LoggerInited = true;
	}
}
