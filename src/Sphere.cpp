#include "Ray.hpp"
#include "Hittable.hpp"
#include "Sphere.hpp"

#include <math.h> 

bool Sphere::Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vector3D oc = r.Origin() - center_;
    auto a      = r.Direction().LengthSquared();
    auto half_b = Dot(oc, r.Direction());
    auto c      =  oc.LengthSquared() - radius_ * radius_;

    auto discriminant = half_b*half_b - a*c;
    if(discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || root > t_max)
            return false;
    }

    rec.t       = root;
    rec.p       = r.at(rec.t);
    rec.normal  = (rec.p - center_) / radius_;

    return true;
}