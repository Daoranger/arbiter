#include "Arbiter/AI/Utility/Action.h"

float arbiter::Action::ComputeScore()
{
    float score {1.0f};

    for (auto& consideration : m_considerations)
    {
        score *= consideration.Evaluate(//factor);
    }

    return score;
}
