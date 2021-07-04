#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Sphere.hpp"
#include "Hittable.hpp"
#include <math.h>
#include <limits>
#include "Utils.hpp"


Ray::Ray() {}
Ray::Ray(const Point3D& origin, const Vector3D& direction) : o_(origin) , dir_(direction) {}

Point3D Ray::Origin() const { return o_; }
Vector3D Ray::Direction() const { return dir_; }

Point3D Ray::at(double t) const {
    return o_ + t*dir_;
}
