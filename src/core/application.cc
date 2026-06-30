#include "application.h"

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
        ProcessInput();
        Update();
        Render();
    }
}

void Application::Shutdown()
{
    window_.Shutdown();
    SDL_Quit();
}

void Application::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            running_ = false;
        }
    }
}

void Application::Update()
{
}

void Application::Render()
{
}
