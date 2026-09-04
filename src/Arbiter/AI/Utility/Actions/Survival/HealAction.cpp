#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/StepCurve.h"

arbiter::HealAction::HealAction()
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Health"));
    AddConsideration(Consideration(std::make_unique<StepCurve>(), "MedCount"));
}

void arbiter::HealAction::Execute()
{
    std::cout << "Healing\n";
}
