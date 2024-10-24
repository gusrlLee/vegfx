#include "vegfx_window.h"
#include "vegfx_log.h"

namespace vegfx {
	ref<Window> Window::s_instance = nullptr;

	void Window::init(WindowCreateInfo info)
	{
		s_instance = make<Window>(info);
	}

	ref<Window>& Window::get()
	{
		return s_instance;
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