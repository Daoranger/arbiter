#pragma once

#include "Action.h"

namespace arbiter
{
    class TakeCoverAction : public Action
    {
    public:
        void Execute() override;
    };
}
