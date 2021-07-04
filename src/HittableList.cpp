#include "Hittable.hpp"
#include "HittableList.hpp"

#include <memory>
#include <vector>

HittableList::HittableList() {}
HittableList::HittableList(shared_ptr<Hittable> object) { Add(object); }

void HittableList::Clear() { objects_.clear(); }
void HittableList::Add(shared_ptr<Hittable> object) { objects_.push_back(object); }


bool HittableList::Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    HitRecord temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects_) {
        if (object->Hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}