#include "vegfx.h"
#include "vegfx_log.h"
#include "vegfx_window.h"


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

	}
	void terminate()
	{
		glfwTerminate();
	}
}