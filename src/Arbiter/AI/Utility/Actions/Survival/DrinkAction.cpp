#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LinearCurve.h"

arbiter::DrinkAction::DrinkAction()
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(1.0f, 0.0f), "Health"));
}

void arbiter::DrinkAction::Execute()
{
    std::cout << "Drinking water\n";
}
