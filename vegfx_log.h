#pragma once 
#include "vegfx_pch.h"
#include "spdlog/spdlog.h"

namespace vegfx {
	class Log {
	public:
		static void init();
		static ref<spdlog::logger>& get() { return sLogger; };

	private:
		static ref<spdlog::logger> sLogger;
	};
}