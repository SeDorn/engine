#include "gtest/gtest.h"
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
