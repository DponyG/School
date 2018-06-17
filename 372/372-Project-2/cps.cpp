#include <vector>
using std::vector;
#include <fstream>
using std::ofstream;
#include <iostream>
using std::endl;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
#include "headers/Shape.h"
#include "headers/SimpleShapes.h"
#include "headers/ComplexShapes.h"
#include "headers/UniqueShapes.h"


int makePostscriptFile(vector<shared_ptr<Shape>> &allShapes,const string &filename){

    ofstream myfile;
    myfile.open (filename + ".ps");
    for(auto shape : allShapes){
        myfile << shape->finalize() << endl;
    }
    myfile.close();

    return 0;
}
