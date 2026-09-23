//
// Created by hoang on 9/2/2026.
//

#include "Arbiter/Entity/Entity.h"

#include <cmath>
#include <iostream>

#include "Arbiter/AI/Utility/Actions/Survival/EatAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/SleepAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"

arbiter::Entity::Entity()
    : m_circle(50.0f)
    , m_leftHand(20.0f)
    , m_rightHand(20.0f)
{
    m_circle.setOrigin(sf::Vector2f(50.0f, 50.0f));
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setOutlineColor(sf::Color::Black);
    m_circle.setOutlineThickness(-2.0f);

    for (sf::CircleShape* hand : { &m_leftHand, &m_rightHand })
    {
        hand->setOrigin(sf::Vector2f(20.0f, 20.0f));
        hand->setFillColor(sf::Color::Red);
        hand->setOutlineColor(sf::Color::Black);
        hand->setOutlineThickness(-2.0f);
    }

    kinematic.position = sf::Vector2f(450.0f, 50.0f);
    kinematic.maxSpeed = 100.0f;
    kinematic.maxAcceleration = 200.0f;

    agent.AddAction(std::make_unique<EatAction>());
    agent.AddAction(std::make_unique<DrinkAction>());
    agent.AddAction(std::make_unique<SleepAction>());
    agent.AddAction(std::make_unique<HealAction>());

    blackboard.Set("Health", currentHealth/maxHealth);
    blackboard.Set("Hunger", currentHunger/maxHunger);
    blackboard.Set("Thirst", currentThirst/maxThirst);
    blackboard.Set("Energy", currentEnergy/maxEnergy);
    blackboard.Set("MedCount", medCount);
    blackboard.Set("FoodCount", foodCount);
    blackboard.Set("WaterCount", waterCount);
}

void arbiter::Entity::Update(float dt)
{
    steering.Update(kinematic, dt);

    if (kinematic.velocity.lengthSquared() > 1.0f)
        kinematic.orientation = std::atan2(kinematic.velocity.y, kinematic.velocity.x);

    agent.Decide(blackboard, *this, dt);
}

void arbiter::Entity::Render(sf::RenderTarget& target)
{
    sf::Vector2f forward(std::cos(kinematic.orientation), std::sin(kinematic.orientation));
    sf::Vector2f side(-forward.y, forward.x);

    m_leftHand.setPosition(kinematic.position + forward * 45.0f - side * 42.0f);
    m_rightHand.setPosition(kinematic.position + forward * 45.0f + side * 42.0f);
    m_circle.setPosition(kinematic.position);

    target.draw(m_circle);
    target.draw(m_leftHand);
    target.draw(m_rightHand);
}
