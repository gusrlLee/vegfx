#pragma once
#include "vegfx_pch.h"

namespace vegfx {
	class Application {
	public:
		Application();
		~Application();
	
		static Application* get() { return mInstance;  }
		void run();

	private:
		// instance 
		static Application* mInstance;
	};

}