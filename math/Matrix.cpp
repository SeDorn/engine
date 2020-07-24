#include "Matrix.h"

using namespace Math;

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols)
{
  m_data = new float*[rows];
  
  for(int i = 0; i < rows; i++)
    m_data[i] = new float[cols];
}

Matrix::~Matrix()
{
  for(int i = 0; i < m_rows; i++)
    delete[] m_data[i];
  
  delete[] m_data;
}
