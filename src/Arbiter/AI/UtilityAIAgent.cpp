#include "Arbiter/AI/Utility/UtilityAIAgent.h"

#include <iostream>

void arbiter::UtilityAIAgent::AddAction(std::unique_ptr<Action> action)
{
    m_actions.push_back(std::move(action));
}

void arbiter::UtilityAIAgent::Decide(const Blackboard& blackboard)
{
    Action* chosenAction {nullptr};
    float highestScore {0.0f};

    for (const auto& action : m_actions)
    {
        float score = action->ComputeScore(blackboard);
        std::cout << score << "\n";
        if (score >= highestScore)
        {
            highestScore = score;
            chosenAction = action.get();
        }
    }

    if (chosenAction)
    {
        chosenAction->Execute();
    }
}
