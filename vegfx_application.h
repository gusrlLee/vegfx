#pragma once

namespace vegfx {
	class Application {
	public:
		Application();
		~Application();

	private:
		static Application* s_instance;

	};

}