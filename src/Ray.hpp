#pragma once
#include "Vector3D.hpp"
#include "Color.hpp"

class Ray {
    public:
        Ray();
        Ray(const Point3D& origin, const Vector3D& direction);

        Point3D Origin() const;
        Vector3D Direction() const;

        Point3D at(double t) const;

    public:
        Point3D o_;
        Vector3D dir_;
};

Color RayColor(const Ray& r);

