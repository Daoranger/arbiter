#include <gtest/gtest.h>

#include "../include/Arbiter/AI/Utility/Curves/LinearCurve.h"

TEST(LinearCurveTest, DirectRelationship)
{
    arbiter::LinearCurve curve(1.0f, 0.0f);
    EXPECT_FLOAT_EQ(curve.Evaluate(0.5f), 0.5f);
}

TEST(LinearCurveTest, InvertedRelationship)
{
    arbiter::LinearCurve curve(-1.0f, 1.0f);
    EXPECT_FLOAT_EQ(curve.Evaluate(0.2f), 0.8f);
}