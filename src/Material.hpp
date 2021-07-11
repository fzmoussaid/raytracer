#pragma once

#include "Ray.hpp"
// #include "Color.hpp"

struct HitRecord;

class Material {
    public:
        virtual bool Scatter( const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered ) const = 0;
};