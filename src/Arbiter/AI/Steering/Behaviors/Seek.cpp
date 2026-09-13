#include "Arbiter/AI/Steering/Behaviors/Seek.h"

arbiter::Seek::Seek(sf::Vector2f target)
    : m_target(target)
{
}

sf::Vector2f arbiter::Seek::GetSteering(const Kinematic& kinematic) const
{
    sf::Vector2f direction = m_target - kinematic.position;

    if (direction.lengthSquared() == 0.0f)
    {
        // desired velocity when reached target is 0, 0 - velocity = -velocity
        return -kinematic.velocity;
    }

    sf::Vector2f desiredVelocity = direction.normalized() * kinematic.maxSpeed;
    return desiredVelocity - kinematic.velocity;
}

void arbiter::Seek::SetTarget(sf::Vector2f target)
{
    m_target = target;
}
