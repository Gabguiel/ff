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
  void Image::h_mirror(){
    for(int x = 0; x < width()/2; x++){
      for (int y = 0; y < height(); y++){
        //pixels.find({width()-x-1,y})->second={at(x,y).red(),at(x,y).green(), at(x,y).blue()};
        //pixels.find({width()-x-1,y})->second.change_color(at(x,y).red(),at(x,y).green(), at(x,y).blue());
        pixels[{width()-x-1,y}] = at(x,y);
      }
    }
  }
  void Image::v_mirror(){
    for(int x = 0; x < width(); x++){
      for (int y = 0; y < height()/2; y++){
        //pixels.find({x,height()-y-1})->second={at(x,y).red(),at(x,y).green(), at(x,y).blue()};
        pixels[{x,height()-y-1}] = at(x,y);
      }
    }
  }
  void Image::add(const Image& img, rgb_value r, rgb_value g, rgb_value b,  int x, int y){
    Color cmp={r,g,b};
    for(int i = x , i2 = 0 ; i < this->image_width && i2 < img.width() ; i++, i2++){
      for(int j = y, j2 = 0 ; j < this->image_height && j2 < img.height() ; j++, j2++){
        if(!(pixels.find({i,j})->second == cmp)){
          pixels.find({i,j})->second=at(i2,j2);
        }
      }
    }
  }

  void Image::crop(int x, int y, int w, int h){
  this->image_width = w;
  this->image_height = h;

  std::map<Pixel, Color> cropped_pixels;
  for (auto& pixel : pixels) {
    int px = pixel.first.x;
    int py = pixel.first.y;
    int new_x = px - x;
    int new_y = py - y;
    Pixel new_pixel{new_x, new_y};
    cropped_pixels[new_pixel] = pixel.second;
    }

  pixels = cropped_pixels;
}
void Image::rotate_left() {
    std::map<Pixel, Color> rotated_pixels;

    for (const auto& entry : this->pixels) {
        const Pixel& pixel = entry.first;
        const Color& color = entry.second;

        int new_x = pixel.y;
        int new_y = this->image_width - 1 - pixel.x;

        Pixel rotated_pixel { new_x, new_y };

        rotated_pixels[rotated_pixel] = color;
    }


    int width2 = this->image_height;
    int height2 = this->image_width;
    this->image_width = width2;
    this->image_height = height2;
    this->pixels = std::move(rotated_pixels);

}

void Image::rotate_right(){
  std::map<Pixel, Color> rotated_pixels;

    for (const auto& entry : this->pixels) {
        const Pixel& pixel = entry.first;
        const Color& color = entry.second;

        int new_x = this->image_height - 1 - pixel.y;
        int new_y = pixel.x;

        Pixel rotated_pixel { new_x, new_y };

        rotated_pixels[rotated_pixel] = color;
    }

    int width2 = this->image_height;
    int height2 = this->image_width;
    this->image_width = width2;
    this->image_height = height2;

    this->pixels = std::move(rotated_pixels);
}
  
}
