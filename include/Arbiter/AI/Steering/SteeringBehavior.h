#pragma once

#include <SFML/System/Vector2.hpp>

#include "Arbiter/AI/Kinematic.h"

namespace arbiter
{
    class SteeringBehavior
    {
    public:
        virtual ~SteeringBehavior() = default;
        virtual sf::Vector2f GetSteering(const Kinematic& kinematic) const = 0;
    };
}
