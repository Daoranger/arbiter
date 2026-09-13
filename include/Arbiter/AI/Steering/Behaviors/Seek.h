#pragma once

#include "Arbiter/AI/Steering/SteeringBehavior.h"

namespace arbiter
{
    class Seek : public SteeringBehavior
    {
    public:
        explicit Seek(sf::Vector2f target);

        sf::Vector2f GetSteering(const Kinematic& kinematic) const override;

        void SetTarget(sf::Vector2f target);

    private:
        sf::Vector2f m_target;
    };
}
