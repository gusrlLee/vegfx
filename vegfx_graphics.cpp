#include "vegfx_graphics.h"
#include "vegfx_log.h"
#include "vegfx_utils.h"

#define VMA_IMPLEMENTATION
#include <vk_mem_alloc.h>

namespace vegfx {
	Graphics::Graphics(GraphicsCreateInfo info)
	{
		mGraphicsInfo = info;

		// application information 
		VkApplicationInfo appInfo{};
		appInfo.pApplicationName = "VEGFX APP";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "VEGFX ENGINE";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_3;

		// check extensions & layers
		bool result = false; 
		result = checkSupportedExtensions(mGraphicsInfo.glfwExtensionList.data(), mGraphicsInfo.glfwExtensionList.size());
		if (!result)
		{
			VEGFX_ERROR("Not support extensions..");
			abort();
		}
		result = checkSupportedLayers(mGraphicsInfo.layerList.data(), mGraphicsInfo.layerList.size());
		if (!result)
		{
			VEGFX_ERROR("Not support layers..");
			abort();
		}

		// instance information
		VkInstanceCreateInfo instanceInfo{};
		instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
#if __APPLE__
		instanceInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
#endif
		instanceInfo.enabledExtensionCount = static_cast<uint32_t>(mGraphicsInfo.glfwExtensionList.size());
		instanceInfo.ppEnabledExtensionNames = mGraphicsInfo.glfwExtensionList.data();
		instanceInfo.enabledLayerCount = static_cast<uint32_t>(mGraphicsInfo.layerList.size());
		instanceInfo.ppEnabledLayerNames = mGraphicsInfo.layerList.data();

		VEGFX_CHECK(vkCreateInstance(&instanceInfo, nullptr, &mVkInstance));
		
		// setting debug messenger 
		if (mGraphicsInfo.bIsUsedValidationLayer)
		{
			VkDebugUtilsMessengerCreateInfoEXT debugMessengerInfo = createDebugMessengerCreateInfo();
			VEGFX_CHECK(createDebugUtilsMessengerEXT(mVkInstance, &debugMessengerInfo, nullptr, &mVkDebugMessenger));
		}

		// create device


	}

	Graphics::~Graphics()
	{
		if (mGraphicsInfo.bIsUsedValidationLayer)
		{
			destroyDebugUtilsMessengerEXT(mVkInstance, mVkDebugMessenger, nullptr);
		}

		vkDestroyInstance(mVkInstance, nullptr);
	}

	bool Graphics::checkSupportedExtensions(const char** extensionNameList, int extensionCount)
	{
		uint32_t supportedExtensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtensionCount, nullptr);
		std::vector<VkExtensionProperties> supportedExtensionList(supportedExtensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtensionCount, supportedExtensionList.data());

		bool bIsFound = false;
		for (int i = 0; i < extensionCount; i++)
		{
			const char* extensionName = extensionNameList[i];
			bIsFound = false;

			for (VkExtensionProperties supportedExtension : supportedExtensionList)
			{
				if (strcmp(extensionName, supportedExtension.extensionName) == 0)
				{
					bIsFound = true;
					break;
				}
			}
			if (!bIsFound)
			{
				return false;
			}
		}

		return true;
	}

	bool Graphics::checkSupportedLayers(const char** layerNameList, int layerCount)
	{
		uint32_t supportedLayerCount = 0;
		vkEnumerateInstanceLayerProperties(&supportedLayerCount, nullptr);
		std::vector<VkLayerProperties> supportedLayerList(supportedLayerCount);
		vkEnumerateInstanceLayerProperties(&supportedLayerCount, supportedLayerList.data());

		bool bIsFound = false;
		for (int i = 0; i < layerCount; i++)
		{
			const char* layerName = layerNameList[i];

			bIsFound = false;
			for (VkLayerProperties supportedLayer : supportedLayerList)
			{
				if (strcmp(layerName, supportedLayer.layerName) == 0)
				{
					bIsFound = true;
					break;
				}
			}
			if (!bIsFound)
			{
				return false;
			}
		}

		return true;
	}

}