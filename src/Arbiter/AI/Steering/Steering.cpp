#include "Arbiter/AI/Steering/Steering.h"

#include <algorithm>

void arbiter::Steering::Update(Kinematic& kinematic, float dt)
{
    sf::Vector2f totalForce(0.0f, 0.0f);
    sf::Vector2f acceleration(0.0f, 0.0f);

    for (const auto& behavior : m_behaviors)
    {
        totalForce += behavior->GetSteering(kinematic);
    }

    // clamp acceleration
    if (totalForce.length() > kinematic.maxAcceleration)
        acceleration = totalForce.normalized() * kinematic.maxAcceleration;
    else
        acceleration = totalForce;

    kinematic.velocity += acceleration * dt;

    // clamp velocity
    if (kinematic.velocity.length() > kinematic.maxSpeed)
    {
        kinematic.velocity = kinematic.velocity.normalized() * kinematic.maxSpeed;
    }

    kinematic.position += kinematic.velocity * dt;
}

void arbiter::Steering::AddBehavior(std::unique_ptr<SteeringBehavior> behavior)
{
    m_behaviors.push_back(std::move(behavior));
}

void arbiter::Steering::ClearBehaviors()
{
    m_behaviors.clear();
}
