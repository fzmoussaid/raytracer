#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"

struct HitRecord {
    Point3D p;
    Vector3D normal;
    double t;
};

class Hittable {
    public:
        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};
