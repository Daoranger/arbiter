#pragma once

#include "Arbiter/AI/Utility/Actions/Action.h"

namespace arbiter
{
    class SleepAction : public Action
    {
    public:
        SleepAction();
        void Execute() override;
    };
}
