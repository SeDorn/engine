#ifndef ENGINE_VECTOR_H
#define ENGINE_VECTOR_H
namespace Math
{
  class Vector
  {
    public:
      Vector(float x_, float y_);
      Vector(float x, float y, float z);
      
      float operator* (const Vector& b) const;
      
      Vector operator* (float factor) const;
      void operator*= (float factor);
      
      void print() const;
      
      float x;
      float y;
      float z;
  };
}


#endif //ENGINE_VECTOR_H
