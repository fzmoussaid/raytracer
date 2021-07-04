#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Hittable.hpp"
#include "Utils.hpp"

#include <ostream>

void WriteColor(std::ostream &out, Color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';

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