#include "Arbiter/AI/Utility/Actions/Survival/EatAction.h"

#include "Arbiter/AI/Steering/Behaviors/Seek.h"
#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"
#include "Arbiter/ECS/Entity.h"

arbiter::EatAction::EatAction()
    : Action("Eat")
{
    AddConsideration(Consideration(std::make_unique<LinearCurve>(-1.0f, 1.0f), "Hunger"));
    AddConsideration(Consideration(std::make_unique<ThresholdCurve>(0.0f), "FoodCount"));
}

void arbiter::EatAction::Execute(Entity& entity, float dt)
{
    entity.steering.ClearBehaviors();
    entity.steering.AddBehavior(std::make_unique<Seek>(sf::Vector2f(450.0f, 50.0f)));
}
