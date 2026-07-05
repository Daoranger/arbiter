#ifndef ARBITERENGINE_APPLICATION_H
#define ARBITERENGINE_APPLICATION_H

#include "window.h"
#include "input.h"


class Application {
public:
    Application();
    ~Application();

    bool Initialize();
    void Run();
    void Shutdown();

private:
    void Update();
    void Render();

    bool running_;
    Window window_;
    Input input_;
};



#endif //ARBITERENGINE_APPLICATION_H
