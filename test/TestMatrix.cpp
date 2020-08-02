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

TEST_F(TestMatrix, MatrixMultiplication)
{
  int rows = 4;
  int cols = 4;
  
  int data[4][4] = {{1, 1, 1, 1},
                   {2, 2, 2, 2},
                   {3, 3, 3, 3},
                   {4, 4, 4, 4}};
  
  int result_data[4][4] = {{10, 10, 10, 10},
                           {20, 20, 20, 20},
                           {30, 30, 30, 30},
                           {40, 40, 40, 40}};
  
  Math::Matrix m1(rows, cols);
  Math::Matrix m2(rows, cols);
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      m1[row][col] = data[row][col];
      m2[row][col] = data[row][col];
    }
  }
  
  Math::Matrix result = m1 * m2;
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      ASSERT_EQ(result[row][col], result_data[row][col]);
    }
  }
}

TEST_F(TestMatrix, EqualMatrix)
{
  int rows = 4;
  int cols = 4;
  
  int data[4][4] = {{1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
  
  Math::Matrix m1(rows, cols);
  Math::Matrix m2(rows, cols);
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      m1[row][col] = data[row][col];
      m2[row][col] = data[row][col];
    }
  }
  
  ASSERT_TRUE(m1 == m2);
}

TEST_F(TestMatrix, Subtraction)
{
  int rows = 4;
  int cols = 4;
  
  int data[4][4] = {{1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
  
  Math::Matrix m1(rows, cols);
  Math::Matrix m2(rows, cols);
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      m1[row][col] = data[row][col];
      m2[row][col] = data[row][col];
    }
  }
  
  Math::Matrix result = m1 - m2;
  
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      ASSERT_EQ(result[row][col], 0);
    }
  }
}



