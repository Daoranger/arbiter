#pragma once

#include "Arbiter/AI/Blackboard.h"
#include "Arbiter/AI/Utility/UtilityAIAgent.h"
#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/EatAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/SleepAction.h"

namespace arbiter
{
    class Entity
    {
    public:
        Entity();
        void Update();

        float currentHealth = 100.0f, maxHealth = 100.0f;
        float currentEnergy = 100.0f, maxEnergy = 100.0f;
        float currentHunger = 100.0f, maxHunger = 100.0f;
        float currentThirst = 100.0f, maxThirst = 100.0f;

        float medCount = 1.0f;
        float foodCount = 1.0f;
        float waterCount = 1.0f;

        Blackboard blackboard;
        UtilityAIAgent agent;

        std::unique_ptr<HealAction> healAction = std::make_unique<HealAction>();
        std::unique_ptr<EatAction> eatAction  = std::make_unique<EatAction>();
        std::unique_ptr<DrinkAction> drinkAction  = std::make_unique<DrinkAction>();
        std::unique_ptr<SleepAction> sleepAction = std::make_unique<SleepAction>();
    };
}



