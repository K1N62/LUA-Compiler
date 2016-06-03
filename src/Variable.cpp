#include "Variable.h"

Variable::Variable(string n, Type t)
{
  this->name = n;
  this->type = t;
}

Variable::~Variable()
{
  // Nothing
}
