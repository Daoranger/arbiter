#include "Arbiter/AI/Utility/Actions/Combat/TakeCoverAction.h"

#include <iostream>

arbiter::TakeCoverAction::TakeCoverAction()
    : Action("TakeCover")
{
}

void arbiter::TakeCoverAction::Execute(Entity& entity, float dt)
{
    std::cout << "Taking Cover\n";
}
