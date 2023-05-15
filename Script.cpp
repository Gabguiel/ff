#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {
    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }
    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            // Other commands require an image to be previously loaded.
            if (command == "save") {
                save();
                continue;
            } 
            // TODO ...
            if (command == "invert"){
                this->image->invert();
                continue;
            }
            if (command == "to_gray_scale"){
                this->image->to_gray_scale();
                continue;
            }
            if (command == "replace"){
                replace();
                continue;
            }
            if (command == "fill"){
                fill();
                continue;
            }
            if(command=="h_mirror"){
                this->image->h_mirror();
                continue;
            }
            if(command== "v_mirror"){
                this->image->v_mirror();
                continue;
            }


        }
    }
    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }
    void Script::blank() {
        // Replace current image (if any) with blank image.
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }
    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }
    void Script::replace(){

        rgb_value r1,g1,b1,r2,g2,b2;
        
        input>>r1>>g1>>b1>>r2>>g2>>b2;
        this->image->replace(r1,g1,b1,r2,g2,b2);
    }
    void Script::fill(){
        int x,y,w,h,r,g,b;

        input>>x>>y>>w>>h>>r>>g>>b;
        this->image->fill(x,y,w,h,r,g,b);
    }
}
