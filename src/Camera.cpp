#include "Utils.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Camera.hpp"

Camera::Camera() {
    auto aspect_ratio = 16.0 / 9.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    Origin_             = Point3D(0, 0, 0);
    Horizontal_         = Vector3D(viewport_width, 0.0, 0.0);
    Vertical_           = Vector3D(0.0, viewport_height, 0.0);
    LowerLeftCorner_    = Origin_ - Horizontal_/2 - Vertical_/2 - Vector3D(0, 0, focal_length);
}

Ray Camera::GetRay(double u, double v) const {
    return Ray(Origin_, LowerLeftCorner_ + u*Horizontal_ + v*Vertical_ - Origin_);
}