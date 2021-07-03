#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"

Ray::Ray() {}
Ray::Ray(const Point3D& origin, const Vector3D& direction) : o_(origin) , dir_(direction) {}

Point3D Ray::Origin() const { return o_; }
Vector3D Ray::Direction() const { return dir_; }

Point3D Ray::at(double t) const {
    return o_ + t*dir_;
}

Color RayColor(const Ray& r) {
    Vector3D unit_direction = UnitVector(r.Direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*Color(1, 1, 1) + t*Color(0.5, 0.7, 1);
}
