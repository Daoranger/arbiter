#include "Arbiter/AI/Utility/Actions/Action.h"

arbiter::Action::Action(std::string name)
    : m_name(std::move(name))
{
}

float arbiter::Action::ComputeScore(const Blackboard& blackboard)
{
    float score {1.0f};

    for (const auto& consideration : m_considerations)
    {
        score *= consideration.Evaluate(blackboard);
    }

    return score;
}

void arbiter::Action::AddConsideration(Consideration consideration)
{
    m_considerations.push_back(std::move(consideration));
}

std::string arbiter::Action::GetName() const
{
    return m_name;
}
