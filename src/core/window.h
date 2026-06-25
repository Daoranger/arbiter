//
// Created by hoang on 6/18/2026.
//

#include <string>
#include <SDL3/SDL.h>

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

class Window
{
public:
    Window(std::string title, int width, int length);                               // default constructor
    ~Window();

private:
    
    std::string title_;
    int width_;
    int length_;
};

#endif //GAMEENGINE_WINDOW_H
