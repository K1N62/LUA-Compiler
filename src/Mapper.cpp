#include "Mapper.h"
#include "Node.h"
#include "BBlock.h"

Mapper::Mapper(BBlock* s, Node* r)
{
  this->start = s;
  this->root = r;
}

Mapper::~Mapper()
{
  // Nothing
}
