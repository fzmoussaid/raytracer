#include "Lambertian.hpp"
#include "Ray.hpp"
#include "Color.hpp"
#include "Hittable.hpp"


Lambertian::Lambertian(const Color& a) : albedo_(a) {}

bool Lambertian::Scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
    auto scatter_direction = rec.normal + RandomUnitVector();
    
    if (scatter_direction.NearZero())
        scatter_direction = rec.normal;
    
    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo_;
    return true;
}