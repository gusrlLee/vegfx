#include "vegfx_utils.h"
#include "vegfx_log.h"

namespace vegfx {
    void printSupportedExtensionsByInstance()
    {
        uint32_t supportedExtensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtensionCount, nullptr);
        std::vector<VkExtensionProperties> supportedExtensionList(supportedExtensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtensionCount, supportedExtensionList.data());

        std::cout << "Supported extensions list : " << std::endl;
        for (VkExtensionProperties supportedExtension : supportedExtensionList)
        {
             std::cout << "\t" << supportedExtension.extensionName << std::endl;
        }
    }
    
    void printSupportedLayersByInstance()
    {
        uint32_t supportedLayerCount = 0;
        vkEnumerateInstanceLayerProperties(&supportedLayerCount, nullptr);
        std::vector<VkLayerProperties> supportedLayerList(supportedLayerCount);
        vkEnumerateInstanceLayerProperties(&supportedLayerCount, supportedLayerList.data());

        std::cout << "Supported layer list : " << std::endl;
        for (VkLayerProperties supportedLayer : supportedLayerList)
        {
            std::cout << "\t" << supportedLayer.layerName << std::endl;
        }
    }

    void printSupportedDeviceList(VkInstance& instance)
    {
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
        if (deviceCount == 0)
        {
            throw std::runtime_error("Failed to find GPUs with Vulkan API support!");
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);

    }

    void setRequiredExtensions(EngineCreateInfo &info)
    {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExntensionList;
        glfwExntensionList = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        std::vector<const char*> requiredGlfwExtensionsList(glfwExntensionList, glfwExntensionList + glfwExtensionCount);
        if (info.bIsUsedValidationLayer)
        {
            requiredGlfwExtensionsList.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

#if __APPLE__    
        requiredGlfwExtensionsList.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
#endif

        info.glfwExtensionList = requiredGlfwExtensionsList;
    }

    void setRequiredLayers(EngineCreateInfo &info)
    {
        std::vector<const char*> requiredLayerList;
        if (info.bIsUsedValidationLayer)
        {
            requiredLayerList.push_back("VK_LAYER_KHRONOS_validation");
        }

        info.layerList = requiredLayerList;
    }

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData) {

        std::cerr << "[VALIDATION LAYER]: " << pCallbackData->pMessage << std::endl;

        return VK_FALSE;
    }

    VkDebugUtilsMessengerCreateInfoEXT createDebugMessengerCreateInfo()
    {
        VkDebugUtilsMessengerCreateInfoEXT createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        createInfo.pfnUserCallback = debugCallback;
        createInfo.pUserData = nullptr; // Optional
        return createInfo;
    }

    VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
        auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        }
        else {
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }

    void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }

}