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
        std::vector<std::unique_ptr<Action>> m_actions;
    };
}
