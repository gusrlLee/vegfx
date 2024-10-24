#include "vegfx.h"
#include "vegfx_log.h"

#include "vegfx_utils.h"
#include "vegfx_window.h"
#include "vegfx_engine.h"

namespace vegfx {
	void init()
	{
		Log::init();
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		// create window
		WindowCreateInfo windowCreateInfo;
		windowCreateInfo.title = "Very Easy Computer Graphics";
		windowCreateInfo.width = 1080;
		windowCreateInfo.height = 720;
		Window::init(windowCreateInfo);

		// crate engine
		EngineCreateInfo engineCreateInfo;

#if _DEBUG
		VEGFX_LOG("Current device support list:");
		printSupportedExtensionsByInstance();
		printSupportedLayersByInstance();
		engineCreateInfo.bIsUsedValidationLayer = true;
#else 
		engineCreateInfo.bIsUsedValidationLayer = false;
#endif

		setRequiredExtensions(engineCreateInfo);
		setRequiredLayers(engineCreateInfo);
		Engine::init(engineCreateInfo);

	}
	void terminate()
	{
		glfwTerminate();
	}
}