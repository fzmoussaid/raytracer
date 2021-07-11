#pragma once

#include "Ray.hpp"
#include "Color.hpp"
#include "Hittable.hpp"

class Lambertian : public Material {
    public:
        Lambertian(const Color& a);

        virtual bool Scatter(
            const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered
        ) const override;

    public:
        Color albedo_;
};
