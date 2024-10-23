cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)

if (WIN32)
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")
endif()

project(vegfx)

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

add_library(vegfx-core 

	vegfx_pch.h
	vegfx_structs.h

	vegfx_application.h
	vegfx_application.cpp
	
	vegfx_window.h
	vegfx_window.cpp

	vegfx_log.h
	vegfx_log.cpp

)

target_link_libraries(vegfx-core Vulkan::Vulkan)
target_link_libraries(vegfx-core glfw)
target_link_libraries(vegfx-core glm::glm-header-only)
target_link_libraries(vegfx-core spdlog::spdlog_header_only)


add_executable(${PROJECT_NAME}
	main.cpp
)

target_link_libraries(${PROJET_NAME} vegfx-core)
