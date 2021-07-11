#pragma once

class Camera {
    public:
        Camera();
        Ray GetRay(double u, double v) const;

    private:
        Point3D Origin_;
        Point3D LowerLeftCorner_;
        Vector3D Horizontal_;
        Vector3D Vertical_;
};