#pragma once 
#include "vegfx_pch.h"
#include "vegfx_structs.h"

namespace vegfx {

	class Graphics {
	public:
		Graphics(GraphicsCreateInfo info);
		~Graphics();

	private:
		
		bool checkSupportedExtensions(const char** extensionNameList, int extensionCount);
        bool checkSupportedLayers(const char** layerNameList, int layerCount);

		GraphicsCreateInfo mGraphicsInfo;

		VkInstance mVkInstance;
		VkDebugUtilsMessengerEXT mVkDebugMessenger = VK_NULL_HANDLE;

		VkPhysicalDevice mVkPhysicalDevice;
		VkDevice mVkDevice;
		VkSurfaceKHR mVKSurface;

	};
}