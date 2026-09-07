#pragma once

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class ShootAction : public Action
    {
    public:
        void Execute() override;
    };
}
