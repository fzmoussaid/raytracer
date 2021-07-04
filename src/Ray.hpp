#pragma once
#include "Vector3D.hpp"

class Ray {
    public:
        Ray();
        Ray(const Point3D& origin, const Vector3D& direction);

        Point3D Origin() const;
        Vector3D Direction() const;

        Point3D at(double t) const;

    private:
        Point3D o_;
        Vector3D dir_;
};


