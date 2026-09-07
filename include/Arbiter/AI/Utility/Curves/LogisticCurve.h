#pragma once
#include "Arbiter/AI/Utility/Curves/ResponseCurve.h"

namespace arbiter
{
    class LogisticCurve : public ResponseCurve
    {
    public:
        LogisticCurve(float steepness, float midpoint);
        float Evaluate(float factor) const override;

    private:
        float m_steepness;  // k, higher k make transition from 0 to 1 more abruptly around mid-point
        float m_midpoint;   // x0, control where transition happened, without it transition always at x = 0 (e.g. x = 0.3 mean health dropping below 30%)
    };
};

