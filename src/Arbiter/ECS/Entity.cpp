//
// Created by hoang on 9/2/2026.
//

#include "Arbiter/ECS/Entity.h"

#include "Arbiter/AI/Utility/Actions/Survival/EatAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/SleepAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"

arbiter::Entity::Entity()
{
    kinematic.position = sf::Vector2f(450.0f, 300.0f);
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
    agent.Decide(blackboard, *this, dt);
}
