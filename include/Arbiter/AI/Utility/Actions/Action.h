#pragma once

#include <vector>

#include "Arbiter/AI/Utility/Consideration.h"
#include "Arbiter/AI/Blackboard.h"

namespace arbiter
{
    class Action
    {
    public:
        virtual ~Action() = default;
        virtual float ComputeScore(const Blackboard& blackboard);
        virtual void Execute() = 0;
        void AddConsideration(Consideration consideration);
    protected:
        std::vector<Consideration> m_considerations;
    };
}

