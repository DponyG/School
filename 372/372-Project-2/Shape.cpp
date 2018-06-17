    #include <string>
    using std::string;
    #include <sstream>
    using std::stringstream;
    #include "headers/Shape.h"
    void Shape::addLocation(string &s){
        stringstream ss;
        ss << xPos << " " << yPos << " translate " << s << " stroke";
        s = ss.str();
        return;
    }
    void Shape::saveRestore(string &s){
        s = "gsave " + s + " grestore";
        return;
    }
    string Shape::finalize(){
        auto s = getPostscript();
        addLocation(s);
        saveRestore(s);
        return s;
    }
    void Shape::setHeight(const int &h){
        height = h;
    }
    void Shape::setWidth(const int &w){
        width = w;
    }
    int Shape::getLocX(){
        return xPos;
    }
    int Shape::getLocY(){
        return yPos;
    }
    int Shape::getHeight(){
        return height;
    }
    int Shape::getWidth(){
        return width;
    }
    void Shape::setCursor(const int &x,const int &y){
        xPos = x;
        yPos = y;
    }