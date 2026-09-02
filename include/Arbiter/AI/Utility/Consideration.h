#pragma once

#include <memory>

#include "Curves/ResponseCurve.h"
#include "Arbiter/AI/Blackboard.h"


namespace arbiter
{
    class Consideration
    {
    public:
        Consideration(std::unique_ptr<ResponseCurve> curve, std::string factorKey);
        float Evaluate(const Blackboard& blackboard) const;

    private:
        std::unique_ptr<ResponseCurve> m_curve;
        std::string m_factorKey;
    };
}
