#include "Arbiter/AI/Blackboard.h"

#include <iostream>

float arbiter::Blackboard::Get(const std::string& key) const
{
    auto it = m_values.find(key);

    if (it != m_values.end())
    {
        return it->second;
    }

    std::cerr << "Key doesn't exist\n";
    return 0.0f;
}

void arbiter::Blackboard::Set(const std::string& key, float value)
{
    m_values[key] = value;
}
