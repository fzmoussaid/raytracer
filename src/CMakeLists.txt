add_library(vector SHARED Vector3D.cpp)
add_library(color SHARED Color.cpp)

add_executable(bin_main main.cpp)

target_link_libraries(bin_main vector color)
