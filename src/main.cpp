#include <iostream>

#include "Color.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "HittableList.hpp"
#include "Utils.hpp"
#include "Camera.hpp"
#include "Metal.hpp"
#include "Lambertian.hpp"



int main() {
    // Image Settings
    const double AspectRatio    = 16.0 / 9.0;
    const int ImageWidth        = 400;
    const int ImageHeight       = static_cast<int>(ImageWidth / AspectRatio);
    const int SamplesPerPixel   = 100;
    const int depth             = 50;

    //World
    HittableList World;
    auto material_ground = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Lambertian>(Color(0.7, 0.3, 0.3));
    auto material_left   = make_shared<Metal>(Color(0.8, 0.8, 0.8));
    auto material_right  = make_shared<Metal>(Color(0.8, 0.6, 0.2));

    World.Add(make_shared<Sphere>(Point3D( 0.0, -100.5, -1.0), 100.0, material_ground));
    World.Add(make_shared<Sphere>(Point3D( 0.0,    0.0, -1.0),   0.5, material_center));
    World.Add(make_shared<Sphere>(Point3D(-1.0,    0.0, -1.0),   0.5, material_left));
    World.Add(make_shared<Sphere>(Point3D( 1.0,    0.0, -1.0),   0.5, material_right));

    // Camera 
    Camera cam;
    std::cout << "P3\n" << ImageWidth << ' ' << ImageHeight << "\n255\n";

    for (int j = ImageHeight-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < ImageWidth; i++) {
            Color PixelColor(0,0,0);
            for (int s = 0; s <SamplesPerPixel; s++) {
                double x = double(i + RandomDouble()) / (ImageWidth-1);
                double y = double(j + RandomDouble()) / (ImageHeight-1); 
                Ray r = cam.GetRay(x, y);
                PixelColor += RayColor(r, World, depth);                    
            }
        
            WriteColor(std::cout, PixelColor, SamplesPerPixel);
        }
        std::cerr << "\nDone\n";
    }

    return 0;
}