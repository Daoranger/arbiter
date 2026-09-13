#pragma once

#include "Arbiter/AI/Blackboard.h"
#include "Arbiter/AI/Kinematic.h"
#include "Arbiter/AI/Utility/Brain.h"
#include "Arbiter/AI/Steering/Steering.h"

namespace arbiter
{
    class Entity
    {
    public:
        Entity();
        void Update(float dt);

        float currentHealth = 10.0f, maxHealth = 100.0f;
        float currentEnergy = 1.0f, maxEnergy = 100.0f;
        float currentHunger = 0.1f, maxHunger = 100.0f;
        float currentThirst = 100.0f, maxThirst = 100.0f;

        float medCount = 1.0f;
        float foodCount = 1.0f;
        float waterCount = 1.0f;

        Blackboard blackboard;
        Kinematic kinematic;
        Brain agent;
        Steering steering;
    };
}



