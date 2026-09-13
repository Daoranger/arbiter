#include "Arbiter/AI/Utility/Actions/Combat/SurrenderAction.h"

#include <iostream>
#include <algorithm>

arbiter::SurrenderAction::SurrenderAction()
    : Action("Surrender")
{
}

float arbiter::SurrenderAction::ComputeScore(const Blackboard& blackboard)
{
    float score {0.0f};

    for (const auto& consideration : m_considerations)
    {
        score = std::max(score, consideration.Evaluate(blackboard));
    }

    return score;
}

void arbiter::SurrenderAction::Execute(Entity& entity, float dt)
{
    std::cout << "Surrendering\n";
}
