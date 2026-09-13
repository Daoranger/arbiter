#include "Arbiter/AI/Utility/Actions/Survival/HealAction.h"

#include "Arbiter/AI/Steering/Behaviors/Seek.h"
#include "Arbiter/AI/Utility/Curves/LogisticCurve.h"
#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Curves/ThresholdCurve.h"
#include "Arbiter/ECS/Entity.h"

arbiter::HealAction::HealAction()
    : Action("Heal")
{
    AddConsideration(Consideration(std::make_unique<LogisticCurve>(-15.0f, 0.3f), "Health"));
    AddConsideration(Consideration(std::make_unique<ThresholdCurve>(0.0f), "MedCount"));
}

void arbiter::HealAction::Execute(Entity& entity, float dt)
{
    entity.steering.ClearBehaviors();
    entity.steering.AddBehavior(std::make_unique<Seek>(sf::Vector2f(450.0f, 550.0f)));
}
