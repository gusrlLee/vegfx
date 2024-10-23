#include "vegfx.h"

class PathTracing : public vegfx::Application {
public:
    PathTracing() {}
    ~PathTracing() {}
};

int main()
{
    vegfx::init();

    vegfx::ref<PathTracing> tracer = vegfx::make<PathTracing>();
    tracer->run();

    vegfx::terminate();
    return 0;
}