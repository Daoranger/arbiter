#include "../../../../../include/Arbiter/AI/Utility/Curves/LinearCurve.h"

#include <algorithm>

arbiter::LinearCurve::LinearCurve(float slope, float intercept)
    : m_slope(slope)
    , m_intercept(intercept)
{
}

float arbiter::LinearCurve::Evaluate(float factor) const
{
    float score = m_slope * factor + m_intercept;
    score = std::clamp(score, 0.0f, 1.0f);
    return score;
}
