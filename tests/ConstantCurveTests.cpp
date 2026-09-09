#include <gtest/gtest.h>

#include "../include/Arbiter/AI/Utility/Curves/ConstantCurve.h"

TEST(ConstantCurve, ValueWithinRange)
{
    arbiter::ConstantCurve curve(0.11f);
    EXPECT_FLOAT_EQ(curve.Evaluate(0.5f), 0.11f);
}

TEST(ConstantCurve, ValueBelowRangeReturnZero)
{
    arbiter::ConstantCurve curve(-0.1f);
    EXPECT_FLOAT_EQ(curve.Evaluate(0.5f), 0.0f);
}

TEST(ConstantCurve, ValueBelowRangeReturnOne)
{
    arbiter::ConstantCurve curve(1.1f);
    EXPECT_FLOAT_EQ(curve.Evaluate(0.5f), 1.0f);
}