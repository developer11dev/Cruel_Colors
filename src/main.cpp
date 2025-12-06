#include "PixelGrid.hpp"
#include <iostream>

int main() {
    PixelGrid grid(300, 400);

    // White background
    grid.clear(255, 255, 255);

    // A few test pixels
    grid.setPixel(150, 200, 255, 0, 0); // Red
    grid.setPixel(151, 200, 0, 255, 0); // Green
    grid.setPixel(152, 200, 0, 0, 255); // Blue

    if (grid.savePPM("output.ppm")) {
        std::cout << "Saved output.ppm\n";
    } else {
        std::cout << "Failed to save image.\n";
    }

    return 0;
}