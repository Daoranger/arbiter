#include "Arbiter/Core/Application.h"

#include <iostream>
#include <memory>

#include "Arbiter/AI/Blackboard.h"
#include "Arbiter/AI/Utility/Consideration.h"
#include "Arbiter/AI/Utility/Curves/LinearCurve.h"
#include "Arbiter/AI/Utility/Actions/ShootAction.h"
#include "Arbiter/AI/Utility/Actions/SurrenderAction.h"
#include "Arbiter/AI/Utility/UtilityAIAgent.h"

int main()
{
    arbiter::Blackboard blackboard;
    blackboard.Set("Health", 1.0f);
    blackboard.Set("Ammo", 0.15f);
    blackboard.Set("Morale", 1.0f);

    auto shootAction = std::make_unique<arbiter::ShootAction>();
    shootAction->AddConsideration(
        arbiter::Consideration(std::make_unique<arbiter::LinearCurve>(1.0f, 0.0f), "Health"));
    shootAction->AddConsideration(
        arbiter::Consideration(std::make_unique<arbiter::LinearCurve>(1.0f, 0.0f), "Ammo"));
    shootAction->AddConsideration(
        arbiter::Consideration(std::make_unique<arbiter::LinearCurve>(1.0f, 0.0f), "Morale"));

    auto surrenderAction = std::make_unique<arbiter::SurrenderAction>();
    surrenderAction->AddConsideration(
        arbiter::Consideration(std::make_unique<arbiter::LinearCurve>(-1.0f, 1.0f), "Health"));
    surrenderAction->AddConsideration(
        arbiter::Consideration(std::make_unique<arbiter::LinearCurve>(-1.0f, 1.0f), "Morale"));

    arbiter::UtilityAIAgent agent;
    agent.AddAction(std::move(shootAction));
    agent.AddAction(std::move(surrenderAction));

    agent.Decide(blackboard);

    return 0;


    arbiter::Application app;
    return 0;
}
