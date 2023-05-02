#include "Image.hpp"

namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    this->image_width=w;
    this->image_height=h;

    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < h ; j++){
          pixels[i][j] = fill;
        }
    }

  }
  Image::~Image()
  {
  }
  int Image::width() const
  {
    return this->image_width;
  }
  int Image::height() const
  {
    return this->image_height;
  }

  // TODO: remove this DUMMY_color variable once you have appropriate fields for representing image pixels.
  //Color DUMMY_color;

  Color& Image::at(int x, int y)
  {
    return pixels[x][y];
  }

  const Color& Image::at(int x, int y) const
  {
    return this->pixels[x][y];
  }
}
