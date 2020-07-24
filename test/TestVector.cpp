#include "gtest/gtest.h"
#include "../math/Common.h"
#include "../math/Vector.h"

class TestVector : public ::testing::Test
{
  protected:
    void SetUp() override
    {
    }
    
    void TearDown() override
    {
    }
};

TEST_F(TestVector, Create)
{
  Math::Vector v(1, 2, 3);
  
  ASSERT_EQ(v.x, 1);
  ASSERT_EQ(v.y, 2);
  ASSERT_EQ(v.z, 3);
  
  ASSERT_EQ(v.x, v[0]);
  ASSERT_EQ(v.y, v[1]);
  ASSERT_EQ(v.z, v[2]);
}

TEST_F(TestVector, MultiplyFactor)
{
  Math::Vector v(1, 2, 3);
  
  v = v * 2;
  ASSERT_EQ(v.x, 2);
  ASSERT_EQ(v.y, 4);
  ASSERT_EQ(v.z, 6);
  
  v *= 2;
  ASSERT_EQ(v.x, 4);
  ASSERT_EQ(v.y, 8);
  ASSERT_EQ(v.z, 12);
  
  v = v * 0.5;
  ASSERT_EQ(v.x, 2);
  ASSERT_EQ(v.y, 4);
  ASSERT_EQ(v.z, 6);
}

TEST_F(TestVector, CrossProduct)
{
  Math::Vector a(2, 3, 4);
  Math::Vector b(5, 6, 7);
  
  Math::Vector result = a.cross(b);
  Math::Vector realResult(-3, 6, -3);
  
  ASSERT_EQ(result, realResult);
}

TEST_F(TestVector, Length)
{
  Math::Vector v1(1, 2, 3);
  ASSERT_LE(v1.length() - std::sqrt(1 + 4 + 9), std::numeric_limits<float>::epsilon());
}