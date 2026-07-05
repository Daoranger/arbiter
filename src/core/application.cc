#include "application.h"

#include <iostream>

Application::Application()
    : running_(false)
    , window_("Arbiter Engine", 800, 600)
{
}

Application::~Application() = default;

bool Application::Initialize()
{
    if (!SDL_Init((SDL_INIT_VIDEO)))
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // create sdl window
    window_.Initialize();

    running_ = true;
    return true;
}

void Application::Run()
{
    while (running_)
    {
        input_.ProcessEvents();
        if (input_.QuitRequested())
        {
            running_ = false;
        }

        if (input_.IsKeyDown(SDL_SCANCODE_W))
        {
            std::cout << "W keydown\n";
        }

        if (input_.IsMouseButtonDown(SDL_BUTTON_LEFT))
        {
            std::cout << "Left mouse button down\n";
        }

        Update();
        Render();
    }
}

void Application::Shutdown()
{
    window_.Shutdown();
    SDL_Quit();
}

void Application::Update()
{
}

void Application::Render()
{
}
