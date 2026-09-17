#pragma once

#include "Curve.h"

namespace arbiter
{
    class ConstantCurve : public arbiter::Curve
    {
    public:
        ConstantCurve(float constant);
        float Evaluate(float factor) const override;

    private:
        float m_constant;
    };
}
