#pragma once

#include <string>
#include <unordered_map>

namespace arbiter
{
    class Blackboard
    {
    public:

        void Set(const std::string& key, float value);
        float Get(const std::string& key) const;

    private:
        std::unordered_map<std::string, float> m_values;
    };
}
