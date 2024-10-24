#pragma once 

namespace vegfx {
	typedef struct WIndowCreateInfo {
		std::string title;
		int width;
		int height;
	} WindowCreateInfo;

	typedef struct EngineCreateInfo {
		bool bIsUsedValidationLayer;
		std::vector<const char*> glfwExtensionList;
		std::vector<const char*> layerList;
	} EngineCreateInfo;

	typedef struct GraphicsCreateInfo {
		bool bIsUsedValidationLayer;
		std::vector<const char*> glfwExtensionList;
		std::vector<const char*> layerList;
	} GraphicsCreateInfo;
}