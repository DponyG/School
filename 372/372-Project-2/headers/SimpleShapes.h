#ifndef SIMPLESHAPES_H
#define SIMPLESHAPES_H

#include <string>
using std::string;
#include "Shape.h"

class Circle : public Shape{
private:
    double radius;
public:
    Circle(double r) : radius(r){
        setHeight(r*2);
        setWidth(r*2);
        setCursor(0,0);
    }
    Circle(double r,int x,int y) : radius(r){
        setHeight(r*2);
        setWidth(r*2);
        setCursor(x,y);
    }
    string getPostscript() override;
};
class Triangle : public Shape{
public:
    Triangle(int h){
        setHeight(h);
        setWidth(h);
        setCursor(0,0);
    }
    Triangle(int h,int x,int y){
        setHeight(h);
        setWidth(h);
        setCursor(x,y);
    }
    string getPostscript() override;
};
class Polygon : public Shape{
private:
    int sides;
public:
    Polygon(int s,int h) : sides(s){
        setHeight(h);
        setWidth(h);
        setCursor(0,0);
    }
    Polygon(int s,int h,int x,int y) : sides(s){
        setHeight(h);
        setWidth(h);
        setCursor(x,y);
    }
    string getPostscript() override;
};
class Square : public Shape{
public:
    Square(int h){
        setHeight(h);
        setWidth(h);
        setCursor(0,0);
    }
    Square(int h,int x,int y){
        setHeight(h);
        setWidth(h);
        setCursor(x,y);
    }
    string getPostscript() override;
};
class Rectangle : public Shape{
public:
    Rectangle(int w,int h){
        setHeight(h);
        setWidth(w);
        setCursor(0,0);
    }
    Rectangle(int w,int h,int x,int y){
        setHeight(h);
        setWidth(w);
        setCursor(x,y);
    }
    string getPostscript() override;
};
class Spacer : public Shape{
public:
    Spacer(int w,int h){
        setHeight(h);
        setWidth(w);
        setCursor(0,0);
    }
    Spacer(int w,int h,int x,int y){
        setHeight(h);
        setWidth(w);
        setCursor(x,y);
    }
    string getPostscript() override;
};

#endif