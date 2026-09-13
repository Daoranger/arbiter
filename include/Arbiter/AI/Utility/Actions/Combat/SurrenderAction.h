#pragma once

#include "../Action.h"

namespace arbiter
{
    class SurrenderAction : public Action
    {
    public:
        SurrenderAction();
        float ComputeScore(const Blackboard &blackboard) override;
        void Execute(Entity& entity, float dt) override;
    };
}
