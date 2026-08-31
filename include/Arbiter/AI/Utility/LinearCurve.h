#pragma once

#include "ResponseCurve.h"

namespace arbiter
{
    class LinearCurve : public ResponseCurve
    {
    public:
        LinearCurve(float slope, float intercept);
        float Evaluate(float factor) override;

    private:
        float m_slope;
        float m_intercept;
    };
}
