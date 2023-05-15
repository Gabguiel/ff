#include "Image.hpp"
#include <iostream>

namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    this->image_width=w;
    this->image_height=h;
    /*pixels = new Color*[w];
    for(int i=0;i<w;i++) {
      pixels[i] = new Color[h];
    }

    for(int i=0;i<w;i++){
      for(int j=0;j<h;j++){
          pixels[i][j]=fill;
        }
    }*/
    for(int x = 0; x < w; x++)
      {
        for (int y = 0; y < h; y++)
        {
          pixels[{x,y}] = fill;
        }
      }
  }
  Image::~Image(){}

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
    return pixels[{x,y}];
  }

  const Color& Image::at(int x, int y) const
  {
    return pixels.find({x,y})->second;
  }

  void Image::invert(){
    for(int i=0;i< this->image_width;i++){
      for(int j=0;j<this->image_height;j++){
        pixels.find({i,j})->second.invert();
      }
    }
  }

  void Image::to_gray_scale(){
    for(int i=0;i< this->image_width;i++){
      for(int j=0;j<this->image_height;j++) {
          pixels.find({i,j})->second.to_gray_scale();
        }
      }
  }
  void Image::replace(rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2,rgb_value g2, rgb_value b2){
    Color cmp={r1,g1,b1};
    for(int i=0;i< this->image_width;i++){
      for(int j=0;j<this->image_height;j++) {
        if(pixels.find({i,j})->second == cmp){
          std::cout << 1<< std::endl;
          pixels.find({i,j})->second.change_color(r2, g2 , b2);
        }
      }
    }
  }

  void Image::fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            Color& color = at(i, j);
            color.red() = r;
            color.green() = g;
            color.blue() = b;
        }
    }
}

  
}
