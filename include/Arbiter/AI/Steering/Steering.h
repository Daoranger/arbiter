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
        void Update(Kinematic& kinematic, float dt);
        void AddBehavior(std::unique_ptr<SteeringBehavior> behavior);
        void ClearBehaviors();

    private:
        std::vector<std::unique_ptr<SteeringBehavior>> m_behaviors;
    };
}
