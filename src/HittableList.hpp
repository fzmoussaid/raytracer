#pragma once

#include "Hittable.hpp"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public Hittable {
    public:
        HittableList();
        HittableList(shared_ptr<Hittable> object);

        void Clear();
        void Add(shared_ptr<Hittable> object);

        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

    private:
        std::vector<shared_ptr<Hittable>> objects_;
};
