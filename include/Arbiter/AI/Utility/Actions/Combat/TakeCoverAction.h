#pragma once

#include "../Action.h"

namespace arbiter
{
    class TakeCoverAction : public Action
    {
    public:
        TakeCoverAction();
        void Execute(Entity& entity, float dt) override;
    };
}
