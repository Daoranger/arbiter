#pragma once

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class DrinkAction : public Action
    {
    public:
        DrinkAction();
        void Execute(Entity& entity, float dt) override;
    };
}
