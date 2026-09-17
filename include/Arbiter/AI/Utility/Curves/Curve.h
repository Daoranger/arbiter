#pragma once

namespace arbiter
{
    class Curve
    {
    public:
        virtual ~Curve() = default;
        virtual float Evaluate(float factor) const = 0;
    };
}
