#include "Arbiter/AI/Utility/Curves/ConstantCurve.h"

#include <algorithm>

arbiter::ConstantCurve::ConstantCurve(float constant)
    : m_constant(std::clamp(constant, 0.0f, 1.0f))
{
}

float arbiter::ConstantCurve::Evaluate(float factor) const
{
    return m_constant;
}
