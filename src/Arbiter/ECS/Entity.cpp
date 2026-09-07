//
// Created by hoang on 9/2/2026.
//

#include "Arbiter/ECS/Entity.h"

arbiter::Entity::Entity()
{
    blackboard.Set("Health", currentHealth/maxHealth);
    blackboard.Set("Hunger", currentHunger/maxHunger);
    blackboard.Set("Thirst", currentThirst/maxThirst);
    blackboard.Set("Energy", currentEnergy/maxEnergy);
    blackboard.Set("MedCount", medCount);
    blackboard.Set("FoodCount", foodCount);
    blackboard.Set("WaterCount", waterCount);

    agent.AddAction(std::move(healAction));
    agent.AddAction(std::move(eatAction));
    agent.AddAction(std::move(drinkAction));
    agent.AddAction(std::move(sleepAction));
}

void arbiter::Entity::Update()
{
    agent.Decide(blackboard);
}
