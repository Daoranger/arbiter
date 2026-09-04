#pragma once

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class EatAction : public Action
    {
    public:
        EatAction();
        void Execute() override;
    };
}
