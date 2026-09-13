#pragma once

#include <memory>
#include <vector>

#include "Arbiter/AI/Kinematic.h"
#include "Arbiter/AI/Steering/SteeringBehavior.h"

namespace arbiter
{
    class Steering
    {
    public:
        void Update(float dt);

        Kinematic kinematic;

    private:
        std::vector<std::unique_ptr<SteeringBehavior>> m_behaviors;
    };
}
