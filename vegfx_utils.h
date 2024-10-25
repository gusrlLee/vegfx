#pragma once 

#include "vegfx_pch.h"
#include "vegfx_structs.h"

namespace vegfx {
    void printSupportedExtensionsByInstance();

    void printSupportedLayersByInstance();

    void printSupportedDeviceList(VkInstance &instance);

    void setRequiredExtensions(EngineCreateInfo &info);

    void setRequiredLayers(EngineCreateInfo &info);

    void setPhysicalDevice(EngineCreateInfo& info);
    
    VkDebugUtilsMessengerCreateInfoEXT createDebugMessengerCreateInfo();

    VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);

    void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
}