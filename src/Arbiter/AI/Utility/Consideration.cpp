#include "Arbiter/AI/Utility/Consideration.h"


arbiter::Consideration::Consideration(std::unique_ptr<Curve> curve, std::string factorKey)
    : m_curve(std::move(curve))
    , m_factorKey(std::move(factorKey))
{
}

float arbiter::Consideration::Evaluate(const Blackboard& blackboard) const
{
    float factor = blackboard.Get(m_factorKey);
    return m_curve->Evaluate(factor);
}
