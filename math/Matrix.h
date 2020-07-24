#ifndef ENGINE_MATRIX_H
#define ENGINE_MATRIX_H

namespace Math
{
  class Matrix
  {
    public:
      Matrix(int rows, int cols);
      Matrix() = delete;
    
      ~Matrix();
    
    private:
      int m_rows;
      int m_cols;
      float** m_data;
  };
}

#endif
