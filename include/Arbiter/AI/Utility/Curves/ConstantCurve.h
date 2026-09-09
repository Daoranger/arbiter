#pragma once

#include "ResponseCurve.h"

namespace arbiter
{
    class ConstantCurve : public arbiter::ResponseCurve
    {
    public:
        ConstantCurve(float constant);
        float Evaluate(float factor) const override;

    private:
        float m_constant;
    };
}
