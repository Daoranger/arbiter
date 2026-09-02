#pragma once

#include "Arbiter/AI/Utility/Curves/ResponseCurve.h"

namespace arbiter
{
    class LinearCurve : public ResponseCurve
    {
    public:
        LinearCurve(float slope, float intercept);
        float Evaluate(float factor) const override;

    private:
        float m_slope;
        float m_intercept;
    };
}
