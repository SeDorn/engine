#include "Vector.h"

#include <iostream>

using namespace Math;

Vector::Vector(float x_, float y_) : x(x_), y(y_), z(0)
{
}

Vector::Vector(float x_, float y_, float z_) : x(x_), y(y_), z(z_)
{
}

float Vector::operator*(const Vector& b) const
{
  return this->x * b.x + this->y * b.y + this->z * b.z;
}

Vector Vector::operator*(const float factor) const
{
  return Vector(this->x * factor, this->y * factor, this->z * factor);
}

void Vector::operator*=(const float factor)
{
  this->x *= factor;
  this->y *= factor;
  this->z *= factor;
}

void Vector::print() const
{
  std::cout << "Vector:" << " x: " << x << " y: " << y << " z: " << z << std::endl;
}





