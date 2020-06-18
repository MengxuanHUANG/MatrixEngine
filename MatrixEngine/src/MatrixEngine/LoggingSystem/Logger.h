#pragma once
#include"spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include"Core.h"

namespace MatrixEngine
{
	class Logger
	{
	public:
		static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return m_EngineLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }

		static void Init(const std::string& format = "%^[%T] %n: %v%$");
	private:
		static std::shared_ptr<spdlog::logger> m_EngineLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}


