#include <gtest/gtest.h>

#include "../include/Arbiter/AI/Utility/Curves/ThresholdCurve.h"

TEST(ThresholdCurveTest, BelowThreshold)
{
    arbiter::ThresholdCurve curve(5.0f);
    EXPECT_FLOAT_EQ(curve.Evaluate(4.9f), 0.0f);
}

TEST(ThresholdCurveTest, AboveThreshold)
{
    arbiter::ThresholdCurve curve(5.0f);
    EXPECT_FLOAT_EQ(curve.Evaluate(5.1f), 1.0f);
}

TEST(ThresholdCurveTest, ExactlyAtThreshold)
{
    arbiter::ThresholdCurve curve(5.0f);
    EXPECT_FLOAT_EQ(curve.Evaluate(5.0f), 0.0f);
}
