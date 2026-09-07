//
// Created by hoang on 9/2/2026.
//

#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"

arbiter::ThresholdCurve::ThresholdCurve(float threshold)
    : m_threshold(threshold)
{
}

float arbiter::ThresholdCurve::Evaluate(float factor) const
{
    if (factor <= m_threshold)
    {
        return 0.0;
    }
    return 1.0;
}
