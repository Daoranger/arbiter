#pragma once

#include "Action.h"

namespace arbiter
{
    class ShootAction : public Action
    {
    public:
        void Execute() override;
    };
}
