#pragma once

#include "Action.h"

namespace arbiter
{
    class SurrenderAction : public Action
    {
    public:
        float ComputeScore(const Blackboard &blackboard) override;
        void Execute() override;
    };
}
