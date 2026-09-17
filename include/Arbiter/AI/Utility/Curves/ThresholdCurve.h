#pragma once
#include "Arbiter/AI/Utility/Curves/Curve.h"

namespace arbiter
{
    class ThresholdCurve : public Curve
    {
    public:
        ThresholdCurve(float threshold);
        float Evaluate(float factor) const override;
    private:
        float m_threshold;
    };
}

