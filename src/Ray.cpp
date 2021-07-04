#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"
#include "Sphere.hpp"

Ray::Ray() {}
Ray::Ray(const Point3D& origin, const Vector3D& direction) : o_(origin) , dir_(direction) {}

Point3D Ray::Origin() const { return o_; }
Vector3D Ray::Direction() const { return dir_; }

Point3D Ray::at(double t) const {
    return o_ + t*dir_;
}

Color RayColor(const Ray& r) {
    Sphere sph(Point3D(0,0,-1), 0.5);
    double t_min = -1000;
    double t_max = 1000;
    HitRecord rec;
    if (sph.Hit(r, t_min, t_max, rec)) {
        return 0.5*Color(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
    }
    Vector3D unit_direction = UnitVector(r.Direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*Color(1, 1, 1) + t*Color(0.5, 0.7, 1);
}
