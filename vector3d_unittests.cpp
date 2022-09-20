#include "gtest/gtest.h"
#include "vector3d.hpp"

TEST(Vector3DConstructor,GivenAVector3DInitializedWithNonZeroValues_WhenCheckingComponents_ExpectCorrectValues)
{
  Vector3D testingVector{1.0, 2.0, 3.0};
  EXPECT_EQ(1.0, testingVector.get_x());
  EXPECT_EQ(2.0, testingVector.get_y());
  EXPECT_EQ(3.0, testingVector.get_z());
}

TEST(Vector3DLengthSquared,GivenAVector3DWithAnXValue_WhenCheckingLengthSquared_ExpectCorrectValue)
{
  Vector3D testingVector{2.0, 0.0, 0.0};
  EXPECT_NEAR(testingVector.magnitude_squared(), 4.0, 1e-3);
}

TEST(Vector3DLengthSquared,GivenAVector3DWithAYValue_WhenCheckingLengthSquared_ExpectCorrectValue)
{
  Vector3D testingVector{0.0, 3.0, 0.0};
  EXPECT_NEAR(testingVector.magnitude_squared(), 9.0, 1e-3);
}

TEST(Vector3DLengthSquared,GivenAVector3DWithAZValue_WhenCheckingLengthSquared_ExpectCorrectValue)
{
  Vector3D testingVector{0.0, 0.0, 4.0};
  EXPECT_NEAR(testingVector.magnitude_squared(), 16.0, 1e-3);
}

TEST(Vector3DLengthSquared,GivenAVector3DInitialzedToNonZeros_WhenCheckingLengthSquared_ExpectCorrectValue)
{
  Vector3D testingVector{2.0, 3.0, 4.0};
  EXPECT_NEAR(testingVector.magnitude_squared(), 29, 1e-3);
}

TEST(Vector3DLength,GivenAVector3DInitialzedToNonZeros_WhenCheckingLength_ExpectCorrectValue)
{
  Vector3D testingVector{1.0, 2.0, 3.0};
  EXPECT_NEAR(testingVector.get_magnitude(), 3.741, 1e-3);
}

