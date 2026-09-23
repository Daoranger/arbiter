#pragma once

#include <SFML/Graphics.hpp>

#include "Arbiter/AI/Kinematic.h"

namespace arbiter
{
    class Player
    {
    public:
        Player();
        void Update(float dt, sf::Vector2f mouseWorld);
        void Render(sf::RenderTarget& target);

        Kinematic kinematic;
    private:
        sf::CircleShape m_circle;
        sf::CircleShape m_leftHand;
        sf::CircleShape m_rightHand;
    };
}
