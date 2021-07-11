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
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    out << static_cast<int>(256 * Clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * Clamp(b, 0.0, 0.999)) << '\n';
}


Color RayColor(const Ray& r, const Hittable& world, int depth) {
    HitRecord rec;

    if (depth <= 0)
        return Color(0,0,0);
    
    if (world.Hit(r, 0.001, infinity, rec)) {
        Ray scattered;
        Color attenuation;
        if (rec.MaterialPtr->Scatter(r, rec, attenuation, scattered))
            return attenuation * RayColor(scattered, world, depth-1); 
        return Color(0, 0, 0);
    }

    Vector3D unit_direction = UnitVector(r.Direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*Color(1, 1, 1) + t*Color(0.5, 0.7, 1);
}