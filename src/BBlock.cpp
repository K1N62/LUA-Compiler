#include "BBlock.h"

int labelCounter = 0;
//! Global list of all function blocks
vector<BBlock*> functions;
//! Global list of all general blocks, use exlusivly by garbageCollection
vector<BBlock*> blocks;

string newLabel()
{
  return "lbl" + to_string(labelCounter++);
}

BBlock::BBlock()
{
  if (debug)
    std::cout << "Creating new block @ " << this << std::endl;

  this->trueExit  = NULL;
  this->falseExit = NULL;
  this->label     = newLabel();
  this->id        = labelCounter;
}

BBlock::~BBlock() {
  //! @remark this is a memory leak but also tries to remove same block twice due to cross references
  //if(this->trueExit != NULL) delete this->trueExit;
  //if(this->falseExit != NULL) delete this->falseExit;
}

void BBlock::dump(ostream &os, map<string, int> &varMap, map<string, int> &strMap)
{
  os << endl << "\"\\n" << this->label << ":\\n\\t\"" << endl;

  for (auto i : this->instructions)
    i.translate(os, this, varMap, strMap);

  if (this->trueExit != NULL)
    os << "\"jmp " << trueExit->label << "\\n\\t\"" << endl;
}

void BBlock::addIns(ThreeAd ins)
{
  this->instructions.push_back(ins);
}

void BBlock::print(ofstream& file)
{
  // Print this tag
  file << "\t" << this->label << " " << "[ shape = record, label=\"<true> True|<lbl>" << this->label << " @ " << this << "\\n\\n";

  for(auto& i : this->instructions)
    file << i.dump() << "\\n";

  file << "|<false> False}\" ];" << endl;

  //Print link to exits
  if (this->trueExit != NULL) {
    file << "\t" << this->label << ":true -> " << this->trueExit->label << ":lbl [label=\"true\"];" << endl;
  }

  if (this->falseExit != NULL) {
    file << "\t" << this->label << ":false -> " << this->falseExit->label << ":lbl [label=\"false\"];" << endl;
  }

}
