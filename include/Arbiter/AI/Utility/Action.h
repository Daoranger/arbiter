#pragma once

#include <vector>

#include "Arbiter/AI/Utility/Consideration.h"

namespace arbiter
{
    class Action
    {
    public:
        virtual ~Action() = default;
        virtual float ComputeScore();
        virtual void Execute() = 0;
        void AddConsideration(Consideration consideration);
    private:
        std::vector<Consideration> m_considerations;
    };
}

