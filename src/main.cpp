#include <iostream>

#include "Color.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "HittableList.hpp"
#include "Utils.hpp"



int main() {
    // Image Settings
    const double AspectRatio    = 16.0 / 9.0;
    const int ImageWidth        = 400;
    const int ImageHeight       = static_cast<int>(ImageWidth / AspectRatio);

    //World
    HittableList world;
    world.Add(make_shared<Sphere>(Point3D(0,0,-1), 0.5));
    world.Add(make_shared<Sphere>(Point3D(0,-100.5,-1), 100));

    // Camera Settings
    double ViewportHeight       = 2.0;
    double ViewportWidth        = AspectRatio * ViewportHeight;
    double FocalLength          = 1.0;
    Point3D Origin              = Point3D(0, 0, 0);
    Vector3D Horizontal         = Vector3D(ViewportWidth, 0, 0);
    Vector3D Vertical           = Vector3D(0, ViewportHeight, 0);
    Point3D LowerLeftCorner     = Origin - Horizontal/2 - Vertical/2 - Vector3D(0, 0, FocalLength);

    std::cout << "P3\n" << ImageWidth << ' ' << ImageHeight << "\n255\n";

    for (int j = ImageHeight-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < ImageWidth; i++) {
            double x = double(i) / (ImageWidth-1);
            double y = double(j) / (ImageHeight-1); 
            Ray r(Origin, LowerLeftCorner + x*Horizontal + y*Vertical - Origin);
            Color PixelColor = RayColor(r, world);
            WriteColor(std::cout, PixelColor);
        }
        std::cerr << "\nDone\n";
    }

    return 0;
}