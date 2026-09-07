#include "Arbiter/AI/Utility/Actions/Survival/SleepAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"

arbiter::SleepAction::SleepAction()
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Energy"));
}

void arbiter::SleepAction::Execute()
{
    std::cout << "Sleeping zzzz\n";
}
