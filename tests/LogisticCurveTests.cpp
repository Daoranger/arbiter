#include <gtest/gtest.h>

#include "../include/Arbiter/AI/Utility/Curves/LogisticCurve.h"

TEST(ThresholdCurveTest, AtMidpointReturnsHalf)
{
    // at midpoint score is exactly 0.5
    arbiter::LogisticCurve curve(10.0f, 0.3f);
    EXPECT_FLOAT_EQ(curve.Evaluate(0.3f), 0.5f);
}

TEST(LogisticCurveTest, FarBelowMidpointNearZero)
{
    arbiter::LogisticCurve curve(10.0f, 0.3f);
    EXPECT_NEAR(curve.Evaluate(0.0f), 0.0f, 0.05f);
}

TEST(LogisticCurveTest, FarAboveMidpointNearOne)
{
    arbiter::LogisticCurve curve(10.0f, 0.3f);
    EXPECT_NEAR(curve.Evaluate(0.6f), 1.0f, 0.05f);
}