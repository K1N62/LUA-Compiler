
#include "Condition.h"
#include "BBlock.h"

Condition::Condition() : Node()
{
	this->type = Type::Undefined;
}

Condition::Condition(Type type) : Node()
{
    this->type = type;
}

std::string Condition::getType()
{
    switch (type) {
        case Condition::Type::If:       return "If";

    default:
      return "Undefined";
    }
}

BBlock* Condition::convert(BBlock* out)
{
  if (debug)
    std::cout << "Converting if statement @ " << out << std::endl;

  vector<BBlock*> joins;
  // Create blocks for Test children
  vector<BBlock*> blocks;
  for (size_t i = 0; i < this->size(); i++) {
    blocks.push_back(new BBlock());
  }

  // Link blocks together, false exit go to next block
  for (size_t i = 0; i < blocks.size() - 1; i++) {
    blocks[i]->falseExit = blocks[i+1];
  }

  // Convert each block and save their joinblocks
  for (size_t i = 0; i < this->size(); i++) {
    joins.push_back(this->children[i]->convert(blocks[i]));
  }

  // Add the join block
  BBlock* j = new BBlock();

  // Link blocks together, true exit go to join
  for ( auto jn : joins)
    jn->trueExit = j;

  // Link last block to join 
  blocks[blocks.size() - 1]->falseExit = j;

  // Link current block
  out->trueExit = blocks[0];

  // Return join block as new block
  return j;
}
