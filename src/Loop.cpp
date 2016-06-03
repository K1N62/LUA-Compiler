
#include "Loop.h"
#include "BBlock.h"

Loop::Loop() : Node()
{
    this->type = Type::Undefined;
}

Loop::Loop(Type type) : Node()
{
    this->type = type;
}

std::string Loop::getType()
{
    switch (type) {
        case Loop::Type::Repeat:    return "Repeat";
        case Loop::Type::While:     return "While";

    default:
        return "Undefined";
    }
}

BBlock* Loop::convert(BBlock* out)
{
  if (debug)
    std::cout << "Converting loop @ " << out << std::endl;

  // Create loop block
  BBlock* l = new BBlock();
  // Link current node to loop
  out->trueExit = l;
  // Link loop to itself
  l->trueExit = l;
  // Convert children
  LEFT->convert(l)->trueExit = l;
  // Now create join block and link them
  BBlock* j = new BBlock();

  l->falseExit = j;

  return j;
}
