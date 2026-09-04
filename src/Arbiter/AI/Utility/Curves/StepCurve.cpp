//
// Created by hoang on 9/2/2026.
//

#include "Arbiter/AI/Utility/Curves/StepCurve.h"

StepCurve::StepCurve()
{
}

float StepCurve::Evaluate(float factor) const
{
    if (factor <= 0.0f)
    {
        return 0.0;
    }

    return 1.0;
}
