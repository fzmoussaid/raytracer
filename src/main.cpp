#include <iostream>

#include "Color.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"


int main() {
    // Image
    const double AspectRatio    = 16.0 / 9.0;
    const int ImageWidth        = 400;
    const int ImageHeight       = static_cast<int>(ImageWidth / AspectRatio);

    // Camera
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
            Color PixelColor = RayColor(r);
            WriteColor(std::cout, PixelColor);
        }
        std::cerr << "\nDone\n";
    }

    return 0;
}