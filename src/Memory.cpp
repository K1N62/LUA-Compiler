
#include "Memory.h"
#include "BBlock.h"

Memory::Memory() : Node()
{
    this->type          = Type::Nil;
    this->str           = "Nil";
    this->integer       = 0;
    this->func          = NULL;
}

Memory::Memory(int v) : Node()
{
    if (debug)
        cout << " + Creating new Integer " << " @ " << this << " : " << to_string(value) << endl;
    this->type          = Type::Number;
    this->str           = to_string(value);
    this->integer       = value;
    this->func          = NULL;
    this->name          = to_string(value);
}

Memory::Memory(string v, bool isConstant) : Node()
{
    if (debug) {
      string tmp = isConstant ? "String" : "Variable";
      cout << " + Creating new " << tmp << " @ " << this << " : " << value << endl;
    }
    this->type          = isConstant ? Type::String : Type::Variable;
    this->str           = value;
    this->integer       = 0;
    this->func          = NULL;
    // Set name of node to variable name
    if (!isConstant)
        this->name = value;
}

Memory::Memory(Func* f, bool isSoftLink) : Node()
{
  if (debug)
    cout << " + Creating new Function " << " @ " << func << endl;
 	this->type          = Type::Function;
  this->str           = "*func";
  this->integer       = 0;
 	this->func          = func;
 	this->isSoftLink    = isSoftLink;
}

Memory::~Memory()
{
    if (debug)
        cout << " - Deleting memory " << getType() << " @ " << this << endl;
    if (this->func != NULL && !this->isSoftLink)
        delete this->func;
}

string Memory::getType()
{
  switch (this->type) {
    case Nil:           return "Nil";
    case Number:        return "Number";
    case String:        return "String";
    case Function:      return "Function";
    case Variable:      return "Variable";

    default:
      return "Undefined";
  }
}

BBlock* Memory::convert(BBlock* out)
{
  string l = this->getName();
  string r = l;
  string o = l;
  switch (this->type) {
    case String:        out->addIns(ThreeAd(o, l, r, ThreeAd::Type::String)); return out;
    case Function:      return this->func->convert(out);

    default:
      return out;
  }
}

std::string Memory::evalStr()
{
  return this->str;
}
