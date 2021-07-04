#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"

struct HitRecord {
    Point3D p;
    Vector3D normal;
    double t;
    bool front_face;

    inline void SetFaceNormal(const Ray& r, const Vector3D& outward_normal) {
        front_face = Dot(r.Direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }

};

class Hittable {
    public:
        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};
