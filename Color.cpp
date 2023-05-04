#include "Color.hpp"

namespace prog {
    Color::Color() {
        this->red_=0;
        this->green_=0;
        this->blue_=0;
    }
    Color::Color(const Color& other) {
        this->red_=other.red_;
        this->green_=other.green_;
        this->blue_=other.blue_;

    }
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        this->red_=red;
        this->green_=green;
        this->blue_=blue;
    }
    rgb_value Color::red() const {
        return this->red_;
    }
    rgb_value Color::green() const {
        return this->green_;
    }
    rgb_value Color::blue() const {
        return this->blue_;
    }

    // TODO: remove this DUMMY variable once you have appropriate fields for representing colors.
    //rgb_value DUMMY_rgb_value = 0; 

    rgb_value& Color::red()  {
        return red_;
    }
    rgb_value& Color::green()  {
      return green_;
    }
    rgb_value& Color::blue()  {
      return blue_;
    }

    Color& Color::operator=(const Color& c) {
        this->red_ = c.red_;
        this->green_= c.green_;
        this->blue_= c.blue_;
        return *this;
    }
    
}
