#pragma once

#include <vector>

#include "Arbiter/AI/Utility/Actions/Action.h"
#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/EatAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"
#include "Arbiter/AI/Utility/Actions/Survival/SleepAction.h"

namespace arbiter
{
    class Brain
    {
    public:
        Brain();
        void AddAction(std::unique_ptr<Action> action);
        void Decide(const Blackboard& blackboard);

    private:
        std::unique_ptr<HealAction> healAction = std::make_unique<HealAction>();
        std::unique_ptr<EatAction> eatAction  = std::make_unique<EatAction>();
        std::unique_ptr<DrinkAction> drinkAction  = std::make_unique<DrinkAction>();
        std::unique_ptr<SleepAction> sleepAction = std::make_unique<SleepAction>();
        std::vector<std::unique_ptr<Action>> m_actions;
    };
}
