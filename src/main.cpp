#include <iostream>

#include "Color.hpp"

int main() {
    const int ImageWidth = 256;
    const int ImageHeight = 256;

    std::cout << "P3\n" << ImageWidth << ' ' << ImageHeight << "\n255\n";

    for (int j = ImageHeight-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < ImageWidth; i++) {
            Color PixelColor (double(i) / (ImageWidth-1), 
                              double(j) / (ImageHeight-1), 
                              0.25 );  
            WriteColor(std::cout, PixelColor);
        }
        std::cerr << "\nDone\n";
    }

    return 0;
}