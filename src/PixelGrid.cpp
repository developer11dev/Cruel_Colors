#include "PixelGrid.hpp"
#include <fstream>



PixelGrid::PixelGrid(int w, int h) {
    width = w;
    height = height;
    pixles = std::vector<Pixels>(w * h);

}

// Clear the grid to a specified color.
void PixelGrid::clear(unsigned char r, unsigned char g, unsigned char b) {
    for (auto& p : pixels) {
        p = { r, g, b };
    }
}

// Set an individual pixel color.
// The board color should start at 255, 255, 255, and setting pixels from a bot
// should subtract values from each.
// Some will decrease. Some will increase. Some may do both to different values.
// A color value should never be over 255 and should never be under 0.
void PixelGrid::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    pixels[y * width + x] = { r, g, b };
}



bool PixelGrid::savePPM(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) return false;

    // P3 means human readable. PPM reads width and height.
    out << "P3\n" << width << " " << height << "\n255\n";

    // Each pixel must be read as R G B.
    // Need to use a cast to int from unsigned because it needs to convert from\
    // A character to number.
    for (const auto& p : pixels) {
        out << (int)p.r << " " << (int)p.g << " " << (int)p.b << "\n";
    }

    return true;
}