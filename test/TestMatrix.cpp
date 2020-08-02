#include "gtest/gtest.h"
#include "../math/Common.h"
#include "../math/Matrix.h"

class TestMatrix : public ::testing::Test
{
  protected:
  void SetUp() override
  {
  }
  
  void TearDown() override
  {
  }
};

TEST_F(TestMatrix, CreateAndUse)
{
  int rows = 3;
  int cols = 3;
  
  Math::Matrix m(rows, cols);
  
  // Mem should all be zeroed out
  ASSERT_EQ(m[0][0], 0);
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      m[row][col] = 2.0f;
    }
  }
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      ASSERT_EQ(m[row][col], 2.0f);
    }
  }
}

TEST_F(TestMatrix, ScalarMultiplication)
{
  int rows = 3;
  int cols = 3;
  
  Math::Matrix m(rows, cols);
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      m[row][col] = 1.0f;
    }
  }
  
  m *= 2;
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      ASSERT_EQ(m[row][col], 2);
    }
  }
}
