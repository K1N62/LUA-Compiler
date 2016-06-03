#pragma once

#include <string>
#include <iostream>

using namespace std;

class Variable {

public:
  enum Type {
    String,
    Integer,
    Floating,
    Function,
  };

private:
  string name;
  Type type;

public:
  Variable (string n, Type t);
  virtual ~Variable ();

  string getName() { return this->name; }
  Type getType() { return this->type; }

};
