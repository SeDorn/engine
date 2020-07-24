#include <iostream>
#include "math/Vector.h"
#include "math/Matrix.h"
#include "logger/Logger.h"

using Math::Vector;

int main()
{
  Logger::instance().setEnabled(true);
  
  Vector v1(1, 2, 3);
  v1.print();
  
  Vector v2 = v1 * 2;
  v2.print();
  
  Math::Matrix m(4, 4);
  
  return 0;
}
