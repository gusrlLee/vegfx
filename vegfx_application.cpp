#include "vegfx_application.h"

namespace vegfx {
    Application* Application::mInstance = nullptr;

    Application::Application()
    {
        mInstance = this;
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
    }
}