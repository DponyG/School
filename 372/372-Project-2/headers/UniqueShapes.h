#ifndef UNIQUESHAPES_H_INCLUDED
#define UNIQUESHAPES_H_INCLUDED

#include <string>
using std::string;
#include "Shape.h"

class CircleWithArcs : public Shape{
private:
    double radius;
public:
    CircleWithArcs(double r) : radius(r){
        setHeight(r*2);
    }
    string getPostscript() override;
};

#endif // UNIQUESHAPES_H_INCLUDED