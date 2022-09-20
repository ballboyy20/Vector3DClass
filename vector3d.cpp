#include "vector3d.hpp"
#include <cmath>

Vector3D::Vector3D()
{
}

Vector3D::Vector3D(double x, double y, double z):components{x,y,z}
{
}

double Vector3D::magnitude_squared() const
{
    double lengthSquared{0.0};
    lengthSquared += components[0]*components[0];
    lengthSquared += components[1]*components[1];
    lengthSquared += components[2]*components[2];
    return lengthSquared;
}

double Vector3D::get_magnitude() const
{
  return sqrt(magnitude_squared());
}

double Vector3D::get_x() const
{
  return components[0];
}

double Vector3D::get_y() const
{
  return components[1];
}

double Vector3D::get_z() const
{
  return components[2];
}

