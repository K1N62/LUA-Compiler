#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "Variable.h"

class Node;
class BBlock;

using namespace std;

class Mapper {
private:
  BBlock* start;
  Node*   root;
  map<Variable, int> varMap;

public:
  Mapper (BBlock* s,  Node* r);
  virtual ~Mapper ();

  bool          isVarStr();
  int           getIndex(string var);
  string        getStrings();
  unsigned int  getIntSize();
  unsigned int  getCharSize();
  void          genMap();
};
