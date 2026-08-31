#pragma once

#include "Arbiter/AI/Utility/ResponseCurve.h"

#include <memory>


namespace arbiter
{
    class Consideration
    {
    public:
        explicit Consideration(std::unique_ptr<ResponseCurve> curve);
        float Evaluate(float factor);

    private:
        std::unique_ptr<ResponseCurve> m_curve;
    };
}