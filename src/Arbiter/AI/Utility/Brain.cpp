#include "Arbiter/AI/Utility/Brain.h"

#include <iostream>

arbiter::Brain::Brain()
{
}

void arbiter::Brain::AddAction(std::unique_ptr<Action> action)
{
    m_actions.push_back(std::move(action));
}

void arbiter::Brain::Decide(const Blackboard& blackboard)
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
