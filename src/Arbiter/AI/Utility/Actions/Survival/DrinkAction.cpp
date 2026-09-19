#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"

arbiter::DrinkAction::DrinkAction()
    : Action("Drink")
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Thirst"));
    AddConsideration(Consideration(std::make_unique<ThresholdCurve>(0.0f), "WaterCount"));
}

void arbiter::DrinkAction::Execute(Entity& entity, float dt)
{
    std::cout << "Drinking water\n";
}
