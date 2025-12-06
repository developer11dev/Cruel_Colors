#ifndef PIXELGRID_HPP
#define PIXELGRID_HPP

#include <vector>
#include <string>

struct Pixel {
    // unsigned is better for color channels(0-255).
    unsigned char r, g, b;

};

class PixelGrid {
public:
    PixelGrid(int width, int height);
    
    // Functions
    void clear(unsigned char r, unsigned char g, unsigned char b);
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
    bool savePPM(const std::string& filename) const;

private:
    int width;
    int height;
    std::vector<Pixel> pixels;

};

#endif