#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"

#include <iostream>

#include "Arbiter/AI/Utility/Curves/LogisticCurve.h"
#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"

arbiter::HealAction::HealAction()
{
    AddConsideration(Consideration(std::make_unique<LogisticCurve>(-15.0f, 0.3f), "Health"));
    AddConsideration(Consideration(std::make_unique<ThresholdCurve>(0.0f), "MedCount"));
}

void arbiter::HealAction::Execute()
{
    std::cout << "Healing\n";
}
