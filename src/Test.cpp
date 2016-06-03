
#include "Test.h"
#include "Memory.h"
#include "BBlock.h"

Test::Test() : Node()
{
  this->type = Type::Undefined;
}

Test::Test(Type type) : Node()
{
  this->type = type;
}

std::string Test::getType()
{
    switch (type) {
        case Test::Type::LessThan:          return "LessThan";
        case Test::Type::LessOrEqual:       return "LessOrEqual";
        case Test::Type::GreaterThan:       return "GreaterThan";
        case Test::Type::GreaterOrEqual:    return "GreaterOrEqual";
        case Test::Type::EqualEqual:        return "EqualEqual";
        case Test::Type::NotEqual:          return "NotEqual";
        case Test::Type::And:               return "And";
        case Test::Type::Or:                return "Or";
        case Test::Type::Not:               return "Not";
        case Test::Type::False:             return "False";
        case Test::Type::True:              return "True";

        default:                            return "Undefined";
    }
}

BBlock* Test::convert(BBlock* out)
{
  if (debug)
    std::cout << "Converting test @ " << out << std::endl;

  // First children
  LEFT->convert(out);
  RIGHT->convert(out);

  // Then this node
  string l = LEFT->getName();
  string r = RIGHT->getName();
  string o = this->getName();

  switch (this->type) {
    case LessThan:        out->addIns(ThreeAd(o, l, r, ThreeAd::Type::LessThan)); return out;
    case LessOrEqual:     out->addIns(ThreeAd(o, l, r, ThreeAd::Type::LessOrEqual)); return out;
    case GreaterThan:     out->addIns(ThreeAd(o, l, r, ThreeAd::Type::GreaterThan)); return out;
    case GreaterOrEqual:  out->addIns(ThreeAd(o, l, r, ThreeAd::Type::GreaterOrEqual)); return out;
    case EqualEqual:      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::EqualEqual)); return out;
    case NotEqual:        out->addIns(ThreeAd(o, l, r, ThreeAd::Type::NotEqual)); return out;
    case And:             out->addIns(ThreeAd(o, l, r, ThreeAd::Type::And)); return out;
    case Or:              out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Or)); return out;
    case Not:             out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Not)); return out;
    case False:           out->addIns(ThreeAd(o, l, r, ThreeAd::Type::False)); return out;
    case True:            out->addIns(ThreeAd(o, l, r, ThreeAd::Type::True)); return out;
  default:
    return out;
  }
}
