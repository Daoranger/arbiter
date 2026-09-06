#pragma once
#include "ResponseCurve.h"

namespace arbiter
{
    class StepCurve : public ResponseCurve
    {
    public:
        StepCurve();
        float Evaluate(float factor) const override;
    private:
    };
}

