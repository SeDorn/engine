#include "Matrix.h"
#include "../logger/Logger.h"

using namespace Math;

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols)
{
  m_data = new float*[rows];
  memset(m_data, 0, rows * sizeof(float));
  
  for(int i = 0; i < rows; i++)
  {
    m_data[i] = new float[cols];
    memset(m_data[i], 0, cols * sizeof(float));
  }
  
  Logger::instance().log(LogLevel::INFO, "Allocated memory for matrix");
}

Matrix Matrix::copy(Matrix &to_copy)
{
  Matrix matrix(to_copy.getRows(), to_copy.getCols());
  
  for (int row = 0; row < matrix.getRows(); row++)
  {
    for (int col = 0; col < matrix.getCols(); col++)
    {
      matrix[row][col] = to_copy[row][col];
    }
  }
  
  return matrix;
}

float *Matrix::operator[](int row)
{
  return m_data[row];
}

Matrix Matrix::operator*(float factor)
{
  Matrix copy = Matrix::copy(*this);
  
  for (int row = 0; row < m_rows; row++)
  {
    for (int col = 0; col < m_cols; col++)
    {
      copy[row][col] *= factor;
    }
  }
  
  return copy;
}

void Matrix::operator*=(float factor)
{
  for (int row = 0; row < m_rows; row++)
  {
    for (int col = 0; col < m_cols; col++)
    {
      m_data[row][col] *= factor;
    }
  }
}

Matrix Matrix::operator*(Matrix &b)
{
  Matrix multiplication(getRows(), b.getCols());
  
  for (int i = 0; i < multiplication.getRows(); i++)
  {
    for (int j = 0; j < multiplication.getCols(); j++)
    {
      multiplication[i][j] = 0;
      for (int k = 0; k < multiplication.getCols(); k++)
      {
        multiplication[i][j] += m_data[i][k] * b[k][j];
      }
    }
  }
  
  return multiplication;
}

bool Matrix::operator==(Matrix &b)
{
  for (int row = 0; row < getRows(); row++)
  {
    for (int col = 0; col < getCols(); col++)
    {
      if (std::abs(m_data[row][col] - b[row][col]) > std::numeric_limits<float>::epsilon())
      {
        return false;
      }
    }
  }
  
  return true;
}

Matrix Matrix::operator+(Matrix &b)
{
  Matrix result(getRows(), getCols());
  
  for (int row = 0; 0 < result.getRows(); row++)
  {
    for (int col = 0; col < result.getCols(); col++)
    {
      result[row][col] = m_data[row][col] + b[row][col];
    }
  }
  
  return result;
}

Matrix Matrix::operator-(Matrix &b)
{
  Matrix result(getRows(), getCols());
  
  for (int row = 0; row < result.getRows(); row++)
  {
    for (int col = 0; col < result.getCols(); col++)
    {
      result[row][col] = m_data[row][col] - b[row][col];
    }
  }
  
  return result;
}

Matrix::~Matrix()
{
  for(int i = 0; i < m_rows; i++)
    delete[] m_data[i];
  
  delete[] m_data;
  
  Logger::instance().log(LogLevel::INFO, "Deallocated memory for matrix");
}

int Matrix::getRows() const
{
  return m_rows;
}

int Matrix::getCols() const
{
  return m_cols;
}


