#pragma once
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Hittable.hpp"

#include <ostream>

void WriteColor(std::ostream &out, Color pixel_color, int samples_per_pixel);

Color RayColor(const Ray& r, const Hittable& world);