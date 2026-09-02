#pragma once

namespace arbiter
{
    class Entity
    {
    public:
        Entity();

        float currentHealth = 100.0f, maxHealth = 100.0f;
        float currentEnergy = 100.0f, maxEnergy = 100.0f;
        float currentHunger = 100.0f, maxHunger = 100.0f;
        float currentThirst = 100.0f, maxThirst = 100.0f;
        float bodyTemp      = 37.0f;

        float medCount = 0.0f;
        float foodCount = 0.0f;
        float waterCount = 0.0f;

        Blackboard blackboard;
    };
}



