
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
  string l, r, o, fname;
  Node* param;
  ThreeAd* a;

  switch (this->type) {

    case Param:
      // Get parameters from ListName
      param = LEFT;

      for (size_t i = 0; i < param->size(); i++) {
        l = param->getChild(0)->getName();
        r = l;
        o = "P"+to_string(i);
        out->addIns(ThreeAd(o, l, r, ThreeAd::Type::FuncParam));
      }

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
      //! @todo Split functioncall into callheader call and callfooter
      //! @remark only one parameter and not expression lists

      // convert the parameters first
      RIGHT->convert(out);

      // Function call header
      out->addIns(ThreeAd("FCH", "FCH", "FCH", ThreeAd::Type::FuncCallHead));

      // Special case with print, write and read
      fname = LEFT->evalStr();
      if (fname == "print" || fname == "write" || fname == "read") {
        // Get only first child
        if (RIGHT->size() > 0)
          param = RIGHT->getChild(0);
        else
          param = RIGHT;

        l = LEFT->getName();
        r = param->getName();
        o = this->getName();

        //! @remark memoryleak
        a = new ThreeAd(o, l, r, ThreeAd::Type::FuncCall);

        // Check if print and string or int
        if (param->getType() == "String")
          a->setString(true);

        out->addIns(*a);
      } else {
        // Load parameters
        if (RIGHT->size() > 0)
          for (size_t i = 0; i < RIGHT->size(); i++) {
            l = RIGHT->getChild(i)->getName();
            r = l;
            o = "P" + to_string(i);
            out->addIns(ThreeAd(o, l, r, ThreeAd::Type::FuncCallParam));
          }
        else
          out->addIns(ThreeAd("P0", RIGHT->getName(), RIGHT->getName(), ThreeAd::Type::FuncCallParam));

        // Call function
        l = LEFT->getName();
        r = l;
        o = this->getName();
        out->addIns(ThreeAd(o, l, r, ThreeAd::Type::FuncCall));

      }
      // Function call footer
      out->addIns(ThreeAd("FCF", "FCF", "FCF", ThreeAd::Type::FuncCallFoot));

      return current;

    default:
      return current;
    }
}
