#pragma once

#include "Arbiter/AI/Blackboard.h"
#include "Arbiter/AI/Utility/Brain.h"

namespace arbiter
{
    class Entity
    {
    public:
        Entity();
        void Update();

        float currentHealth = 10.0f, maxHealth = 100.0f;
        float currentEnergy = 100.0f, maxEnergy = 100.0f;
        float currentHunger = 100.0f, maxHunger = 100.0f;
        float currentThirst = 100.0f, maxThirst = 100.0f;

        float medCount = 1.0f;
        float foodCount = 1.0f;
        float waterCount = 1.0f;

        Blackboard blackboard;
        Brain agent;

    };
}



