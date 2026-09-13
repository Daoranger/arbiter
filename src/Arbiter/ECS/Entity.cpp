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
}

void arbiter::Entity::Update(float dt)
{
    steering.Update(kinematic, dt);
    agent.Decide(blackboard, *this, dt);
}
