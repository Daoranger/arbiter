#include "Arbiter/AI/Utility/Curves/LogisticCurve.h"

#include <algorithm>
#include <complex>

arbiter::LogisticCurve::LogisticCurve(float steepness, float midpoint)
    : m_steepness(steepness)
    , m_midpoint(midpoint)
{
}

float arbiter::LogisticCurve::Evaluate(float factor) const
{
    float score = 1.0f / (1.0f + std::exp(-m_steepness * (factor - m_midpoint)));
    score = std::clamp(score, 0.0f, 1.0f);
    return score;
}
