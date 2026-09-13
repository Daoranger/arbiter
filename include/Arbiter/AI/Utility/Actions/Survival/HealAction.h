#pragma once

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class HealAction : public Action
    {
    public:
        HealAction();
        void Execute(Entity& entity, float dt) override;
    };
}

