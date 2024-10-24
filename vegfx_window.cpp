#include "vegfx_window.h"
#include "vegfx_log.h"

namespace vegfx {
	ref<Window> Window::sWindowInstance = nullptr;

	void Window::init(WindowCreateInfo info)
	{
		sWindowInstance = make<Window>(info);
	}

	ref<Window>& Window::get()
	{
		return sWindowInstance;
	}

	Window::Window(WindowCreateInfo info)
	{
		mWindowInfo = info;
		mpWindow = glfwCreateWindow(mWindowInfo.width, mWindowInfo.height, mWindowInfo.title.c_str(), nullptr, nullptr);
		if (!mpWindow)
		{
			VEGFX_ERROR("Failed to create glfw window! :-(");
			glfwTerminate();
			abort();
		}

		VEGFX_INFO("Success to create window!");
	}

	Window::~Window()
	{
		glfwDestroyWindow(mpWindow);
	}

	bool Window::isShouldClose()
	{
		return glfwWindowShouldClose(mpWindow);
	}

	void Window::update()
	{
		glfwPollEvents();
	}

}