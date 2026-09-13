#include "Arbiter/AI/Utility/Actions/Survival/SleepAction.h"

#include "Arbiter/AI/Steering/Behaviors/Seek.h"
#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/ECS/Entity.h"

arbiter::SleepAction::SleepAction()
    : Action("Sleep")
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Energy"));
}

void arbiter::SleepAction::Execute(Entity& entity, float dt)
{
    entity.steering.ClearBehaviors();
    entity.steering.AddBehavior(std::make_unique<Seek>(sf::Vector2f(850.0f, 300.0f)));
}
