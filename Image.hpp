#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
#include <map>

namespace prog
{
  struct Pixel 
  {
  int x, y;
  bool operator<(const Pixel& other) const 
  {
    if (x != other.x) {
      return x < other.x;
    }
    return y < other.y;
  }
  };

  class Image
  {
  private:
    // TODO: define private fields for image state
    int image_width;
    int image_height;
    std::map<Pixel, Color> pixels;
    //Color **pixels;
    //std::vector<std::vector<Color>> pixels;

  public:
    Image(int w, int h, const Color &fill = {255, 255, 255});
    ~Image();
    int width() const;
    int height() const;
    Color &at(int x, int y);
    const Color &at(int x, int y) const;
    void invert();
    void to_gray_scale();
    void replace (rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2,rgb_value g2, rgb_value b2);
    
    void fill(int x,int y,int w,int h, rgb_value r, rgb_value g, rgb_value b);
    void h_mirror();
    void v_mirror();
    void add(const Image& img, rgb_value r, rgb_value g, rgb_value b,  int x, int y);
  };
}
#endif
