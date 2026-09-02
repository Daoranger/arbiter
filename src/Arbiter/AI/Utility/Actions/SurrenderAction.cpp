#include "Arbiter/AI/Utility/Actions/SurrenderAction.h"

#include <iostream>
#include <algorithm>

float arbiter::SurrenderAction::ComputeScore(const Blackboard& blackboard)
{
    float score {0.0f};

    for (const auto& consideration : m_considerations)
    {
        score = std::max(score, consideration.Evaluate(blackboard));
    }

    return score;
}

void arbiter::SurrenderAction::Execute()
{
    std::cout << "Surrendering\n";
}
