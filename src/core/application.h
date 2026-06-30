#ifndef GAMEENGINE_APPLICATION_H
#define GAMEENGINE_APPLICATION_H

#include "window.h"


class Application {
public:
    Application();
    ~Application();

    bool Initialize();
    void Run();
    void Shutdown();

private:
    void ProcessInput();
    void Update();
    void Render();

    bool running_;
    Window window_;
};



#endif //GAMEENGINE_APPLICATION_H
