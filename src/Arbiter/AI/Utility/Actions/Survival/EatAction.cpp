#include "Arbiter/AI/Utility/Actions/Survival/EatAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"

arbiter::EatAction::EatAction()
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Hunger"));
    AddConsideration(Consideration(std::make_unique<ThresholdCurve>(0.0f), "FoodCount"));
}

void arbiter::EatAction::Execute()
{
    std::cout << "Eating food nom nom nom\n";
}
