#pragma once 
#include "vegfx_pch.h"
#include "vegfx_structs.h"

namespace vegfx {
	class Window {
	public:
		static void init(WindowCreateInfo info);
		static ref<Window>& get();

		Window(WindowCreateInfo info);
		~Window();

		GLFWwindow* getNativePtr() { return mpWindow; }
		int getWidth() { return mWindowInfo.width; }
		int getHeight() { return mWindowInfo.height; }

		bool isShouldClose();
		void update();

	private:
		static ref<Window> s_instance;

		GLFWwindow* mpWindow;
		WindowCreateInfo mWindowInfo;
	};
}