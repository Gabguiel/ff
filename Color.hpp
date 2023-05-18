#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

namespace prog
{
  typedef unsigned char rgb_value;
  class Color
  {
    private:
    /**
     * \brief Valores rgb
    */
      rgb_value red_, green_, blue_;

    public:
    /**
     * \brief Default constructor
    */
      Color();
      Color(const Color& c);
      Color(rgb_value r, rgb_value g, rgb_value b);
      rgb_value red() const;
      rgb_value& red();
      rgb_value green() const;
      rgb_value& green();
      rgb_value blue() const;
      rgb_value& blue();

      void invert();
      void to_gray_scale();
      void change_color(rgb_value r, rgb_value g, rgb_value b);
      bool operator==(const Color &c) const;
  };
}
#endif
