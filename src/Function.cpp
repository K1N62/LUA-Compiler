
#include "Function.h"

Function::Function() : Node()
{
  this->type = Type::Undefined;
}

Function::Function(Type t) : Node()
{
  this->type = t;
}

std::string Function::getType()
{
    switch (type) {
        case Function::Type::Name:    return "Name";
        case Function::Type::Call:    return "Call";
        case Function::Type::Body:    return "Body";
        case Function::Type::Param:   return "Param";

        default:
            return "Undefined";
    }
}

BBlock* Function::convert(BBlock* out)
{

  return out;
}
