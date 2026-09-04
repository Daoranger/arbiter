#pragma once
#include "ResponseCurve.h"

class StepCurve : public arbiter::ResponseCurve
{
public:
    StepCurve();
    float Evaluate(float factor) const override;
private:
};

