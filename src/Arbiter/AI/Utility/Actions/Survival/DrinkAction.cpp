#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/StepCurve.h"

arbiter::DrinkAction::DrinkAction()
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Thirst"));
    AddConsideration(Consideration(std::make_unique<StepCurve>(), "WaterCount"));
}

void arbiter::DrinkAction::Execute()
{
    std::cout << "Drinking water\n";
}
