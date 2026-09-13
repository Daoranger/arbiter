#include "Arbiter/AI/Utility/Actions/Survival/DrinkAction.h"

#include "Arbiter/AI/Steering/Behaviors/Seek.h"
#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"
#include "Arbiter/ECS/Entity.h"

arbiter::DrinkAction::DrinkAction()
    : Action("Drink")
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Thirst"));
    AddConsideration(Consideration(std::make_unique<ThresholdCurve>(0.0f), "WaterCount"));
}

void arbiter::DrinkAction::Execute(Entity& entity, float dt)
{
    entity.steering.ClearBehaviors();
    entity.steering.AddBehavior(std::make_unique<Seek>(sf::Vector2f(50.0f, 300.0f)));
}
