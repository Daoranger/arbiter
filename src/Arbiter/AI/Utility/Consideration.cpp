#include "Arbiter/AI/Utility/Consideration.h"


arbiter::Consideration::Consideration(std::unique_ptr<ResponseCurve> curve)
    : m_curve(std::move(curve))
{
}

float arbiter::Consideration::Evaluate(float factor)
{
    return m_curve->Evaluate(factor);
}
