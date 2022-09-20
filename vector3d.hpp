#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <array>

class Vector3D
{
public:
  Vector3D();
  Vector3D(double x, double y, double z);

  double get_magnitude() const;
  double magnitude_squared() const;
  double get_x() const;
  double get_y() const;
  double get_z() const;

protected:
  std::array<double,3> components{0.0,0.0,0.0};
};


#endif // VECTOR3D_HPP
