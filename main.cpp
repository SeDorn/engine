#include <iostream>
#include "math/Vector.h"

using Math::Vector;

int main()
{
  Vector v1(1, 2, 3);
  v1.print();
  
  Vector v2 = v1 * 2;
  v2.print();
  
  return 0;
}
