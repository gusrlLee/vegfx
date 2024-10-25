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

#define VEGFX_LOG(...)		::vegfx::Log::get()->trace(__VA_ARGS__)
#define VEGFX_INFO(...)		::vegfx::Log::get()->info(__VA_ARGS__)
#define VEGFX_ERROR(...)	::vegfx::Log::get()->error(__VA_ARGS__)

#define VEGFX_CHECK(x)						\
	do {									\
		VkResult err = x;					\
		if (err)							\
		{									\
			std::cerr << err << std::endl;  \
			abort();						\
		}									\
	} while(0)								\
