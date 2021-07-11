#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Material.hpp"
#include <memory>

struct HitRecord {
    Point3D p;
    Vector3D normal;
    std::shared_ptr<Material> MaterialPtr;
    double t;
    bool FrontFace;

    inline void SetFaceNormal(const Ray& r, const Vector3D& outward_normal) {
        FrontFace = Dot(r.Direction(), outward_normal) < 0;
        normal = FrontFace ? outward_normal :-outward_normal;
    }

};

class Hittable {
    public:
        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};
