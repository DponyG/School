#include <vector> 
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;

#include "headers/Shape.h"
// Shape
#include "headers/ComplexShapes.h" 
// Rotation
#include "headers/SimpleShapes.h"
// Triangle, Circle, Square, Rectangle
#include "headers/cps.h"
// makePostscriptFile
#include "headers/UniqueShapes.h"
// CircleWithArcs

int main () {
    cout << "PS_Translator main" << endl;
    vector<shared_ptr<Shape>> allShapes;
    shared_ptr<Shape> shape(new Triangle(10));
    shared_ptr<Shape> shape1(new Circle(10));
    shared_ptr<Shape> vertical(new VerticalShape({shape,shape1}));
    shared_ptr<Shape> shape2(new Square(10));
    shared_ptr<Shape> shape3(new Polygon(6,100));
    shared_ptr<Shape> shape4(new Rectangle(6,10));
    shared_ptr<Shape> horizontal(new HorizontalShape({vertical,shape2,shape3,shape4}));
    Rotation angle(270);
    shared_ptr<Shape> rotated(new Rotated(horizontal,angle));
    shared_ptr<Shape> scaled(new Scaled(rotated,1,1));
    scaled->setCursor(200,200);
    allShapes.push_back(scaled);
    shared_ptr<Shape> unique(new CircleWithArcs(72));
    shared_ptr<Shape> rotatedUnique(new Rotated(unique, 90));
    rotatedUnique->setCursor(360,360);
    allShapes.push_back(rotatedUnique);
    makePostscriptFile(allShapes,"mainPS");
    return 0;
}