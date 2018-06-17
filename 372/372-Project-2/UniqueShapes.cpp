#include "headers/UniqueShapes.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

string CircleWithArcs::getPostscript(){
    stringstream ss;
    ss << "0 0 newpath 0 30 360 { 3 copy pop " << radius << " 0 4 index arc closepath stroke pop } for";
    return ss.str();
}