#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

namespace prog
{
  typedef unsigned char rgb_value;
  class Color
  {
    private:
    /**
     * \brief RGB values
    */
      rgb_value red_, green_, blue_;

    public:
    /**
     * \brief Default constructor
    */
      Color();
    /**
     * \brief Copy Constructor
     * @param c Color
    */
      Color(const Color& c);
    /**
     * \brief Constructor with rgb values
     * @param r Value of red_
     * @param g Value of green_
     * @param b Value of blue_
    */
      Color(rgb_value r, rgb_value g, rgb_value b);
    /**
     * @return Get the value of red
    */ 
      rgb_value red() const;
    /**
     * @return Get the reference of red value
    */
      rgb_value& red();
    /**
     * @return Get the value of green
    */ 
      rgb_value green() const;
    /**
     * @return Get the reference of green value
    */
      rgb_value& green();
    /**
     * @return Get the value of blue
    */ 
      rgb_value blue() const;
    /**
     * @return Get the reference of blue value
    */
      rgb_value& blue();

    /**
     * \brief Invert the color,{R,G,B} turns into {255-R,255-G,255-B}
    */
      void invert();
    /**
     * \brief Convert the color to grayscale
    */
      void to_gray_scale();
    /**
     * \brief Change the color to the specified values
     * @param r Value of red_
     * @param g Value of green_
     * @param b Value of blue_ 
    */
      void change_color(rgb_value r, rgb_value g, rgb_value b);
    /**
     * \brief Equality operator
     * @param c Color that's beeing compared to
     * @return '1' if colors are equal, '0' otherwise
    */
      bool operator==(const Color &c) const;
  };
}
#endif
