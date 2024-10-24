#include "vegfx_log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace vegfx {
	ref<spdlog::logger> Log::sLogger;

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] [%n]: %v%$");
		sLogger = spdlog::stdout_color_mt("VEGFX SYSTEM");
	}
}