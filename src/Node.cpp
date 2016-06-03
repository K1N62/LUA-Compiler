
#include "Memory.h"
#include "Node.h"
#include "BBlock.h"
#include "ThreeAd.h"

unsigned int nameCounter = 0;

Node::Node()
{
  this->id        = nameCounter;
  this->type      = Type::Undefined;
  this->local     = false;
  this->testFirst = true;
  this->name      = "_id" + to_string(nameCounter++);
}

Node::Node(Type type)
{
  this->id        = nameCounter;
  this->type      = type;
  this->local     = false;
  this->testFirst = true;
  this->name      = "_id" + to_string(nameCounter++);
}

Node::~Node()
{
    for (auto child : this->children)
        delete child;
}

string Node::getType()
{
    switch (this->type) {
        case Node::Type::ExpressionList:  return "ExpressionList";
        case Node::Type::VariableList:    return "VariableList";
        case Node::Type::FunctionName:    return "FunctionName";
        case Node::Type::FunctionCall:    return "FunctionCall";
        case Node::Type::FunctionBody:    return "FunctionBody";
        case Node::Type::MemberFunction:  return "MemberFunction";
        case Node::Type::ListName:        return "ListName";
        case Node::Type::Stat:            return "Stat";
        case Node::Type::Field:           return "Field";
        case Node::Type::FieldElement:    return "FieldElement";
        case Node::Type::DoubleDot:       return "DoubleDot";
        case Node::Type::Hash:            return "Hash";
        case Node::Type::Negate:          return "Negate";
        case Node::Type::Tridot:          return "Tridot";
        case Node::Type::Return:          return "Return";
        case Node::Type::Do:              return "Do";
        case Node::Type::Test:            return "Test";

        default:
            return "Undefined";
    }
}

void Node::print(ofstream& file)
{
  // Print children
  if (this->getType() == "Function")
    dynamic_cast<Memory*>(this)->getFunc()->print(file);
  else
    for (auto child : this->children)
      child->print(file);

  // Print this tag
  if (this->isLeaf()) {
      file << this->id << " " << "[label=\"" << this->getType() << "\\n" << this->evalStr() << "\"]" << endl;
  } else {
      file << this->id << " " << "[label=\"" << this->getName() << "\\n" << this->getType() << "\"]" << endl;
  }

  // Print link to children
  for (auto child : this->children)
    file << this->id << " -> " << child->getNodeID() << endl;
}

Node* Node::getChild(unsigned int i)
{
  if ( i > this->children.size() - 1 || this->children.size() == 0 )
    return NULL;

  return this->children[i];
}

int Node::moveToFront()
{

  Node* tmp = this->children.back();
  this->children.pop_back();
  this->children.insert(this->children.begin(), tmp);

  return 0;
}

BBlock* Node::convert(BBlock* out)
{
  BBlock* current = out;
  BBlock* func;
  string l, r, o;
  Node* param;
  ThreeAd* a;

  switch (this->type) {
    case FunctionBody:
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
      current = RIGHT->convert(func);

      // Add function footer
      current->addIns(ThreeAd("FF", "FF", "FF", ThreeAd::Type::FuncFoot));
      return out;

    case FunctionCall:
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

    case Return:
      // First child
      current = LEFT->convert(current);

      l = LEFT->getName();
      r = l;
      o = l;
      out->addIns(ThreeAd(o, l, r, ThreeAd::Type::Return));

      // Add function footer
      current->addIns(ThreeAd("FF", "FF", "FF", ThreeAd::Type::FuncFoot));
      return current;

    default:
      for (auto child : this->children) {
        try {
          current = child->convert(current);
        } catch (exception& e) {
          cerr << "Error: " << e.what() << endl;
        }
      }
      return current;
  }

}

void Node::transferChildren(Node* parent) {
  for (auto child : this->children)
    parent->addChild(child);

  this->children = vector<Node*>();
}
