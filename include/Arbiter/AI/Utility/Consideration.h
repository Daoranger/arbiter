#pragma once

#include <memory>

#include "Curves/Curve.h"
#include "Arbiter/AI/Blackboard.h"


namespace arbiter
{
    class Consideration
    {
    public:
        Consideration(std::unique_ptr<Curve> curve, std::string factorKey);
        float Evaluate(const Blackboard& blackboard) const;

    private:
        std::unique_ptr<Curve> m_curve;
        std::string m_factorKey;
    };
}
