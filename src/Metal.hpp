
#pragma once
#include "Color.hpp"

class Metal : public Material {
    public:
        Metal(const Color& a);

        virtual bool Scatter(
            const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered
        ) const override;
    private:
        Color albedo_;
};