#include "window.h"

Window::Window(std::string title, int width, int height)
    : title_(title)
    , width_(width)
    , height_(height)
    , sdl_window_(nullptr)
{
}

Window::~Window()
{
}

bool Window::Initialize()
{
    sdl_window_ = SDL_CreateWindow(
        title_.c_str(),
        width_,
        height_,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_MAXIMIZED);

    if (!sdl_window_)
    {
        SDL_Log("Failed to createt SDL window: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }
    return true;
}

void Window::Shutdown()
{
    SDL_DestroyWindow(sdl_window_);
}
