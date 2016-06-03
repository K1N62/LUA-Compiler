
#include "Memory.h"
#include "Binop.h"
#include "BBlock.h"

Binop::Binop() : Node()
{
  this->type = Type::Undefined;
}

Binop::Binop(Type type) : Node()
{
  this->type = type;
}

std::string Binop::getType()
{
    switch (type) {
        case Binop::Type::Assign:           return "Assign";
        case Binop::Type::Addition:         return "Addition";
        case Binop::Type::Subtraction:      return "Subtraction";
        case Binop::Type::Division:         return "Division";
        case Binop::Type::Multiplication:   return "Multiplication";
        case Binop::Type::Power:            return "Power";
        case Binop::Type::Modulo:           return "Modulo";

        default:
            return "Undefined";
    }
}

BBlock* Binop::convert(BBlock* out)
{
  if (debug)
    std::cout << "Converting binary operation @ " << out << std::endl;

  // First children
  LEFT->convert(out);
  RIGHT->convert(out);

  // Then this node
  string l = LEFT->getName();
  string r = RIGHT->getName();
  string o = this->getName();

  switch (this->type) {
    case Assign:
      o = LEFT->getName();
      l = RIGHT->getName();
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Assign));
      return out;
    case Addition:
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Addition));
      return out;
    case Subtraction:
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Subtraction));
      return out;
    case Division:
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Division));
      return out;
    case Multiplication:
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Multiplication));
      return out;
    case Power:
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Power));
      return out;
    case Modulo:
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Modulo));
      return out;
  default:
    return out;
  }
}
