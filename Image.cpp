#include "Image.hpp"
#include <iostream>

namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    this->image_width=w;
    this->image_height=h;
    pixels = new Color*[w];
    int count =0;
    for(int i=0;i<w;i++) {
      pixels[i] = new Color[h];
    }

    for(int i=0;i<w;i++){
      for(int j=0;j<h;j++){
          pixels[i][j]=fill;
          std::cout<< count;
          count++;
        }
    }
  }
  Image::~Image()
  {
    for(int i=0;i<width();i++){
      delete[] pixels[i];
    }
    delete[] pixels;
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

  void Image::invert(){
    for(int i=0;i< this->image_width;i++){
      for(int j=0;j<this->image_height;j++) {
          pixels[i][j].invert();
        }
      }
  }
}
