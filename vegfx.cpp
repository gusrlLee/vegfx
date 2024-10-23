#include "vegfx.h"
#include "vegfx_log.h"

namespace vegfx {
	void init()
	{
		Log::init();
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	}
	void terminate()
	{
		glfwTerminate();
	}
}