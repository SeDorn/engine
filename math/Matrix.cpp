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


