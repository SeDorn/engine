#ifndef ENGINE_MATRIX_H
#define ENGINE_MATRIX_H

#include "Common.h"

namespace Math
{
  class Matrix
  {
    public:
      Matrix(int rows, int cols);
      Matrix() = delete;
  
      static Matrix copy(Matrix&);
      
      Matrix operator*(float);
      void operator*=(float);
      
      bool operator==(Matrix &);
      
      Matrix operator+(Matrix &);
      Matrix operator-(Matrix &);
      Matrix operator*(Matrix &);
      
      float* operator[](int);
      
      int getRows() const;
      int getCols() const;
    
      ~Matrix();
    
    private:
      int m_rows;
      int m_cols;
      float** m_data;
  };
}

#endif
