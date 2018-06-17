#ifndef CPS_H
#define CPS_H
#include <memory>
using std::shared_ptr;
#include <vector>
using std::vector;

int makePostscriptFile(vector<shared_ptr<Shape>> &allShapes,const string &filename);

#endif