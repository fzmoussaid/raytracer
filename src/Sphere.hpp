#pragma once

#include "Ray.hpp"
#include "Hittable.hpp"
#include <memory>

class Sphere : public Hittable {
    public:
        Sphere() {}
        Sphere(Point3D c, double r, std::shared_ptr<Material> m): center_(c), radius_(r), materialPtr_(m) {}

        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

    private:
        Point3D center_;
        double radius_; 
        std::shared_ptr<Material> materialPtr_;
};