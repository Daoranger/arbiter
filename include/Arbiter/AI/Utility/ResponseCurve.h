#pragma once

namespace arbiter
{
    class ResponseCurve
    {
    public:
        virtual ~ResponseCurve() = default;
        virtual float Evaluate(float factor) = 0;
    };
}
