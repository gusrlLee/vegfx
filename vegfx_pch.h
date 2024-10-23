#pragma once 

// standard header
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <optional>
#include <stdio.h>
#include <fstream>
#include <string>

// glfw library
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// vulkan api
#include <vulkan/vulkan.h>

// shared pointer
template<typename T>
using ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr ref<T> make(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}

// unique pointer not yet.. :-(
