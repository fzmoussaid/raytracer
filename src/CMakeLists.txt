add_library(vector SHARED Vector3D.cpp)
add_library(color SHARED Color.cpp)
add_library(ray SHARED Ray.cpp)
add_library(hittable SHARED Hittable.cpp)
add_library(sphere SHARED Sphere.cpp)
add_library(hittablelist SHARED HittableList.cpp)

add_executable(bin_main main.cpp)

target_link_libraries(bin_main vector color ray hittable hittablelist sphere)
