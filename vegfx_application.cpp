#include "vegfx_application.h"
#include "vegfx_log.h"
#include "vegfx_structs.h"
#include "vegfx_window.h"

namespace vegfx {
    Application* Application::mInstance = nullptr;

    Application::Application()
    {
        VEGFX_INFO("Application Initializaiton!");
        mInstance = this;
    }

    Application::~Application()
    {
        VEGFX_INFO("Application release!");
    }

    void Application::run()
    {
        while (!Window::get()->isShouldClose())
        {
            Window::get()->update();
        }
    }
}