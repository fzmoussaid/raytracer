#pragma once

#include "Ray.hpp"
#include "Hittable.hpp"

class Sphere : public Hittable {
    public:
        Sphere() {}
        Sphere(Point3D c, double r): center_(c), radius_(r) {}

        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

    private:
        Point3D center_;
        double radius_; 
};