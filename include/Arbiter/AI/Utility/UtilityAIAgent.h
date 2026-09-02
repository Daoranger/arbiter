#pragma once

#include <vector>

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class UtilityAIAgent
    {
    public:
        void AddAction(std::unique_ptr<Action> action);
        void Decide(const Blackboard& blackboard);

    private:
        std::vector<std::unique_ptr<Action>> m_actions;
    };
}
