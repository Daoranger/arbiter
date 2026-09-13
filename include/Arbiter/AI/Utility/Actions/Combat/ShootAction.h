#pragma once

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class ShootAction : public Action
    {
    public:
        ShootAction();
        void Execute(Entity& entity, float dt) override;
    };
}
