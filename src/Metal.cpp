#include "Metal.hpp"


Metal::Metal(const Color& a) : albedo_(a) {}

bool Metal::Scatter( const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
    Vector3D reflected = Reflect(UnitVector(r_in.Direction()), rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = albedo_;
    return (Dot(scattered.Direction(), rec.normal) > 0);
}
