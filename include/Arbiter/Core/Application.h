#pragma once

#include <SFML/Graphics.hpp>

#include "Arbiter/Entity/Entity.h"
#include "Arbiter/Entity/Player.h"

namespace arbiter
{
    class Application
    {
    public:
        Application();
        void Run();

    private:
        void ProcessEvents();
        void Update();
        void Render();

        sf::RenderWindow m_window;
        sf::Clock m_clock;
        Entity m_entity;
        Player m_player;
    };
}