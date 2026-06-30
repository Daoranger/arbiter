#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#include <string>
#include <SDL3/SDL.h>

class Window
{
public:
    Window(std::string title, int width, int height);                               // default constructor
    ~Window();

    bool Initialize();
    void Shutdown();

private:
    std::string title_;
    int width_;
    int height_;
    SDL_Window* sdl_window_;
};

#endif //GAMEENGINE_WINDOW_H
