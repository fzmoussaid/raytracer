#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Hittable.hpp"
#include "Utils.hpp"

#include <ostream>

void WriteColor(std::ostream &out, Color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    out << static_cast<int>(256 * Clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(b, 0.0, 0.999)) << '\n';
}


Color RayColor(const Ray& r, const Hittable& world) {
    HitRecord rec;
    if (world.Hit(r, 0, infinity, rec)) {
        return 0.5*( rec.normal+ Color(1,1,1) );
    }
    Vector3D unit_direction = UnitVector(r.Direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*Color(1, 1, 1) + t*Color(0.5, 0.7, 1);
}