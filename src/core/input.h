//
// Created by hoang on 7/2/2026.
//

#ifndef ARBITERENGINE_INPUT_H
#define ARBITERENGINE_INPUT_H
#include "SDL3/SDL_events.h"


class Input
{
public:
    void ProcessEvents();
    bool IsKeyDown(SDL_Scancode key) const;
    void IsMouseButtonDown(Uint8 button) const;
    void GetMousePosition();
    bool QuitRequested();

private:

    bool quit_requested;

};



#endif //ARBITERENGINE_INPUT_H
