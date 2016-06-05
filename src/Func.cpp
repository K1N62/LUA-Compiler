
#include "Func.h"
#include "BBlock.h"
#include "ThreeAd.h"

Func::Func() : Node()
{
  this->type = Type::Name;
}

Func::Func(Type t) : Node()
{
  this->type = t;
}

Func::~Func()
{
  // Nothing
}

std::string Func::getType()
{
    switch (type) {
        case Func::Type::Name:    return "Name";
        case Func::Type::Call:    return "Call";
        case Func::Type::Body:    return "Body";
        case Func::Type::Param:   return "Param";

        default:
            return "Undefined";
    }
}

BBlock* Func::convert(BBlock* out)
{
  BBlock* current = out;
  BBlock* func;
  string l, r, o;
  Node* param;
  ThreeAd* a;

  switch (this->type) {

    case Param:
      // Get parameters from ListName
      param = LEFT;

      l = param->getChild(0)->getName();
      r = l;
      o = "P1";
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::FuncParam));

      return out;

    case Body:
      if (debug)
        std::cout << "Converting function body @ " << out << std::endl;

      // Create new function block
      func = new BBlock();
      func->setLabel(this->funcname);

      // Add function header
      func->addIns(ThreeAd("FH", "FH", "FH", ThreeAd::Type::FuncHead));

      // Add function to functionslist
      functions.push_back(func);

      // Convert the body blocks
      current = LEFT->convert(func);
      current = RIGHT->convert(current);

      // Add function footer
      current->addIns(ThreeAd("FF", "FF", "FF", ThreeAd::Type::FuncFoot));
      return out;

    case Call:
      //! @remark only one parameter and not expression lists
      // First child
      if (RIGHT->getType() == "ExpressionList")
        param = RIGHT->getChild(0);
      else
        param = RIGHT;
      param->convert(out);
      // Then this node
      l = LEFT->getName();
      r = param->getName();
      o = this->getName();

      //! @remark memoryleak
      a = new ThreeAd(o, l, r, ThreeAd::Type::FuncCall);

      // Check if print and string or int
      if (param->getType() == "String")
        a->setString(true);

      out->addIns(*a);
      return current;

    default:
      return current;
    }
}
