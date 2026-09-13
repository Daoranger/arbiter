#pragma once

#include <vector>
#include <string>

#include "Arbiter/AI/Utility/Consideration.h"
#include "Arbiter/AI/Blackboard.h"

namespace arbiter
{
    class Entity;

    class Action
    {
    public:
        Action(std::string name);
        virtual ~Action() = default;
        virtual float ComputeScore(const Blackboard& blackboard);
        virtual void Execute(Entity&, float dt) = 0;
        void AddConsideration(Consideration consideration);

        std::string GetName() const;

    protected:
        std::vector<Consideration> m_considerations;

    private:
        std::string m_name;
    };
}

