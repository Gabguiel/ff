#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
#include <map>

namespace prog
{
  struct Pixel 
  {
  /**
   * \brief value of x
  */
  int x; 
  /**
   * \brief value of y
  */
  int y;
  /*bool operator<(const Pixel& other) const 
  {
    if (x != other.x) {
      return x < other.x;
    }
    return y < other.y;
  }*/
  };

  class Image
  {
  private:
  /**
   * \brief width of image
  */
    int image_width;
  /**
   * \brief height of image
  */
    int image_height;
  /**
   * \brief All pixels of image
  */
    std::map<Pixel, Color> pixels;
  public:
  /**
   * \brief Constructor 
   * @param w width
   * @param h height
   * @param fill color to be associated with each pixel, default color={255,255,255}
  */
    Image(int w, int h, const Color &fill = {255, 255, 255});
  /**
   * \brief Destructor
  */
    ~Image();
  /**
    * @return Get value of width
  */
    int width() const;
  /**
    * @return Get value of heigth
  */
    int height() const;
  /**
   * @param x value of x
   * @param y value of y
   * @return Get reference of color associated to pixel {x,y}
  */
    Color &at(int x, int y);
  /**
   * @param x value of x
   * @param y value of y
   * @return Get color associated to pixel {x,y}
  */
    const Color &at(int x, int y) const;
  /**
   * \brief Inverts the color of all pixels in an image
  */
    void invert();
  /**
   * \brief Turns the color of all pixels in an image to gray scale
  */
    void to_gray_scale();
  /**
   * \brief replaces all pixels with color{r1,g1,b1} to color {r2,g2,b2}
   * @param r1 value of red to compare
   * @param g1 value of green to compare
   * @param b1 value of blue to compare
   * @param r2 value of red to change to
   * @param g2 value of green to change to
   * @param b2 value of blue to change to
  */
    void replace (rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2,rgb_value g2, rgb_value b2);
    
  /**
   * \brief Assign a color to all pixels contained in a rectangle
   * @param x value of x of top-left corner
   * @param y value of y of top-left corner
   * @param w value of width
   * @param h value of height
   * @param r value of red 
   * @param g value of green
   * @param b value of blue
  */
    void fill(int x,int y,int w,int h, rgb_value r, rgb_value g, rgb_value b);
  /**
   * \brief Mirror image horizontally
  */
    void h_mirror();
  /**
   * \brief Mirror image vertically
  */
    void v_mirror();
  /**
   *\brief Copy all pixels from image except the pixels with color {r,g,b}
   * @param img Image to copy the pixels from
   * @param r value of red
   * @param g value of green
   * @param b value of blue
   * @param x value of x of top-left corner
   * @param y value of y of top-left corner
  */
    void add(const Image& img, rgb_value r, rgb_value g, rgb_value b,  int x, int y);
  /**
     * \brief Reduces the image to all pixels contained in the rectangle
     * @param x value x of the top left corner
     * @param y value y of the top left corner
     * @param w value of width
     * @param h value of height
    */
    void crop(int x, int y, int w, int h);
    /**
     * \brief Rotates the image 90 degrees to the left.
    */ 
    void rotate_left();
    /**
     * \brief Rotates the image 90 degrees to the right.
    */
    void rotate_right();
  };
}
#endif
