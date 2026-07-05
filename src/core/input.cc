//
// Created by hoang on 7/2/2026.
//

#include "input.h"

void Input::ProcessEvents()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) == true)
    {
        switch (e.type)
        {
            case SDL_EVENT_QUIT:
            {
                quit_requested = true;
                break;
            }
        }
    }
}

bool Input::IsKeyDown(SDL_Scancode key) const
{
    const bool* state = SDL_GetKeyboardState(nullptr);
    return state[key];
}

void Input::IsMouseButtonDown(Uint8 button) const
{
    const bool* state = SDL_GetMouseState(button);
    return
}

bool Input::QuitRequested()
{
    return quit_requested;
}
