#pragma once
#include "Arbiter/AI/Utility/Curves/ResponseCurve.h"

namespace arbiter
{
    class ThresholdCurve : public ResponseCurve
    {
    public:
        ThresholdCurve(float threshold);
        float Evaluate(float factor) const override;
    private:
        float m_threshold;
    };
}

