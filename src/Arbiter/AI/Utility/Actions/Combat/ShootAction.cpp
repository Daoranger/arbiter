#include <iostream>

#include "Arbiter/AI/Utility/Actions/Combat/ShootAction.h"

arbiter::ShootAction::ShootAction()
    : Action("Shoot")
{
}

void arbiter::ShootAction::Execute(Entity& entity, float dt)
{
    std::cout << "Shooting\n";
}
