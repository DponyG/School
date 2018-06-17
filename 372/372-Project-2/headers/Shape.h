#ifndef SHAPES_H
#define SHAPES_H

#include "string"
using std::string;

class Shape{
private:
    int xPos = 0, 
        yPos = 0, 
        height = 0, 
        width = 0;
public:
    virtual string getPostscript() = 0;
    string finalize();
    void setHeight(const int &h);
    void setWidth(const int &w);
    int getLocX();
    int getLocY();
    int getHeight();
    int getWidth();
    void setCursor(const int &x,const int &y);
    void addLocation(string &s);
    void saveRestore(string &s);
};

#endif