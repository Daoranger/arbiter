#pragma once

#include <SFML/System/Vector2.hpp>

namespace arbiter
{
    class Kinematic
    {
    public:
        sf::Vector2f position;
        sf::Vector2f velocity;

        float orientation = 0.0f;
        float rotation = 0.0f;

        float maxSpeed = 0.0f;
        float maxAcceleration = 0.0f;
    };
}
