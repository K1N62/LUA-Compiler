#include "ThreeAd.h"
#include "BBlock.h"

ThreeAd::ThreeAd(string out, string l, string r, Type t)
{
  this->result    = out;
  this->t         = t;
  this->lhs       = l;
  this->rhs       = r;
  this->isString  = false;
}

string ThreeAd::getType()
{
    switch (t) {
        case ThreeAd::Type::Sequence:         return "Sequence";
        case ThreeAd::Type::String:           return "String";
        case ThreeAd::Type::Assign:           return "Assign";
        case ThreeAd::Type::If:               return "If";
        case ThreeAd::Type::ElseIf:           return "ElseIf";
        case ThreeAd::Type::FuncHead:         return "FuncHead";
        case ThreeAd::Type::FuncFoot:         return "FuncFoot";
        case ThreeAd::Type::FuncCallHead:     return "FuncCallHead";
        case ThreeAd::Type::FuncCallFoot:     return "FuncCallFoot";
        case ThreeAd::Type::FuncCallParam:    return "FuncCallParam";
        case ThreeAd::Type::FuncCall:         return "FuncCall";
        case ThreeAd::Type::FuncParam:        return "FuncParam";
        case ThreeAd::Type::Return:           return "Return";
        case ThreeAd::Type::Addition:         return "Addition";
        case ThreeAd::Type::Subtraction:      return "Subtraction";
        case ThreeAd::Type::Division:         return "Division";
        case ThreeAd::Type::Multiplication:   return "Multiplication";
        case ThreeAd::Type::Modulo:           return "Modulo";
        case ThreeAd::Type::Power:            return "Power";
        case ThreeAd::Type::LessThan:         return "LessThan";
        case ThreeAd::Type::LessOrEqual:      return "LessOrEqual";
        case ThreeAd::Type::GreaterThan:      return "GreaterThan";
        case ThreeAd::Type::GreaterOrEqual:   return "GreaterOrEqual";
        case ThreeAd::Type::EqualEqual:       return "EqualEqual";
        case ThreeAd::Type::NotEqual:         return "NotEqual";
        case ThreeAd::Type::And:              return "And";
        case ThreeAd::Type::Or:               return "Or";
        case ThreeAd::Type::Not:              return "Not";
        case ThreeAd::Type::False:            return "False";
        case ThreeAd::Type::True:             return "True";

        default:
            return "Undefined";
    }
}

string ThreeAd::dump()
{
  return this->result + " := " + this->lhs + " " + this->getType() + " " + this->rhs;
}

void ThreeAd::loadlhs(ostream &os, map<string, int> &varMap)
{
  os << "\"movq ";
  try {
    auto c = stoi(this->lhs);
    os << "$" << c;
  } catch(...) {
    os << varMap[this->lhs] << "(%%" << VAR_REG << ")";
  }
  os << ", %%rax\\n\\t\"" << endl;
}

void ThreeAd::loadrhs(ostream &os, map<string, int> &varMap)
{
  os << "\"movq ";
  try {
    auto c = stoi(this->rhs);
    os << "$" << c;
  } catch(...) {
    os << varMap[this->rhs] << "(%%" << VAR_REG << ")";
  }
  os << ", %%rbx\\n\\t\"" << endl;
}

void ThreeAd::setparam(ostream &os, map<string, int> &varMap, int i)
{
  os << "\"movq ";
  try {
    auto c = stoi(this->lhs);
    os << "$" << c;
  } catch(...) {
    os << varMap[this->lhs] << "(%%" << VAR_REG << ")";
  }
  os << ", ";
  switch (i) {
    case 0: os << "%%rdi"; break;
    case 1: os << "%%rsi"; break;
    case 2: os << "%%rdx"; break;
    case 3: os << "%%rcx"; break;
    case 4: os << "%%r8"; break;
    case 5: os << "%%r9"; break;
  }
  os << "\\n\\t\"" << endl;

}

void ThreeAd::store(ostream &os, map<string, int> &varMap)
{
  // Only store if result is not NS (no store)
  if (this->result != "NS")
    os << "\"movq %%rax, " << varMap[this->result] << "(%%" << VAR_REG << ")" << "\\n\\t\"" << endl;
}

void ThreeAd::translate(ostream &os, BBlock* b, map<string, int> &varMap, map<string, int> &strMap)
{
  int powerCounter;

  // Add debug comment
  os << "\"# --[ " << result << " := " << this->lhs << " " << this->getType() << " " << this->rhs << " ]-- \\n\\t\"" << endl;

  switch (this->t) {
    case FuncParam:
      // Load parameters
      if (this->result == "P0")
        os << "\"movq %%rdi, " << varMap[this->lhs] << "(%%" << VAR_REG << ")\\n\\t\"" << endl;
      else if (this->result == "P1")
        os << "\"movq %%rsi, " << varMap[this->lhs] << "(%%" << VAR_REG << ")\\n\\t\"" << endl;
      else if (this->result == "P2")
        os << "\"movq %%rdx, " << varMap[this->lhs] << "(%%" << VAR_REG << ")\\n\\t\"" << endl;
      else if (this->result == "P3")
        os << "\"movq %%rcx, " << varMap[this->lhs] << "(%%" << VAR_REG << ")\\n\\t\"" << endl;
      else if (this->result == "P4")
        os << "\"movq %%r8, " << varMap[this->lhs] << "(%%" << VAR_REG << ")\\n\\t\"" << endl;
      else if (this->result == "P5")
        os << "\"movq %%r9, " << varMap[this->lhs] << "(%%" << VAR_REG << ")\\n\\t\"" << endl;
        //! @todo Load rest of function load parameters from stack
      break;
    case FuncHead:
      // Push base pointer to stack
      os << "\"pushq %%rbp\\n\\t\"" << endl;
      // Save varible pointer
      os << "\"pushq %%" << VAR_REG << "\\n\\t\"" << endl;
      // Move stack pointer to basepointer
      os << "\"movq %%rsp, %%rbp\\n\\t\"" << endl;
      // Increase the stack (by decreasing the value) for variables
      os << "\"subq $" << varMap.size() * sizeof(double) << ", %%rsp\\n\\t\"" << endl;
      // Save this stackpointer as new VAR_REG
      os << "\"movq %%rsp, %%" << VAR_REG << " \\n\\t\"" << endl;
      break;
    case FuncFoot:
      // Reset the stack pointer
      os << "\"movq %%rbp, %%rsp\\n\\t\"" << endl;
      // Pop the variable pointer
      os << "\"popq %%" << VAR_REG << "\\n\\t\"" << endl;
      // Pop the base pointer
      os << "\"popq %%rbp\\n\\t\"" << endl;
      // Return
      os << "\"ret\\n\\t\"" << endl;
      break;
    case FuncCallHead:
      // push general registers
      os << "\"pushq %%rax\\n\\t\"" << endl;
      os << "\"pushq %%rbx\\n\\t\"" << endl;
      //os << "\"pushq %%" << VAR_REG << "\\n\\t\"" << endl;
      //os << "\"pushq %%" << STR_REG << "\\n\\t\"" << endl;
      break;
    case FuncCallFoot:
      // Pop general registers
      //os << "\"popq %%" << STR_REG << "\\n\\t\"" << endl;
      //os << "\"popq %%" << VAR_REG << "\\n\\t\"" << endl;
      os << "\"popq %%rbx\\n\\t\"" << endl;
      os << "\"popq %%rax\\n\\t\"" << endl;
      break;
    case FuncCallParam:
      // Load parameters
      if (this->result == "P0")
        setparam(os, varMap, 0);
      else if (this->result == "P1")
        setparam(os, varMap, 1);
      else if (this->result == "P2")
        setparam(os, varMap, 2);
      else if (this->result == "P3")
        setparam(os, varMap, 3);
      else if (this->result == "P4")
        setparam(os, varMap, 4);
      else if (this->result == "P5")
        setparam(os, varMap, 5);
      //! @todo Load rest of function call parameters to stack
      break;
    case FuncCall:
      // Special case if print, read and write
      if (this->lhs == "print") {
        loadrhs(os, varMap);
        if (this->isString)
          os << "\"leaq %[printStr], %%rdi\\n\\t\"" << endl;
        else
          os << "\"leaq %[printInt], %%rdi\\n\\t\"" << endl;
        os << "\"movq %%rbx, %%rsi\\n\\t\"" << endl;
        os << "\"movq $0, %%rax\\n\\t\"" << endl;
        os << "\"call printf\\n\\t\"" << endl;
      } else if (this->lhs == "write") {
        loadrhs(os, varMap);
        if (this->isString)
          os << "\"leaq %[writeStr], %%rdi\\n\\t\"" << endl;
        else
          os << "\"leaq %[writeInt], %%rdi\\n\\t\"" << endl;
        os << "\"movq %%rbx, %%rsi\\n\\t\"" << endl;
        os << "\"movq $0, %%rax\\n\\t\"" << endl;
        os << "\"call printf\\n\\t\"" << endl;
      } else if (this->lhs == "read") {
        os << "\"leaq %[readInt], %%rdi\\n\\t\"" << endl;
        os << "\"leaq %[intbuf], %%rsi\\n\\t\"" << endl;
        os << "\"movq $0, %%rax\\n\\t\"" << endl;
        os << "\"call scanf\\n\\t\"" << endl;
        os << "\"movq %[intbuf], %%rax\\n\\t\"" << endl;
      } else {
        os << "\"call " << this->lhs << "\\n\\t\"" << endl;
      }
      store(os, varMap);
      break;
    case Return:
      loadlhs(os, varMap);
      break;
    case String:
      os << "\"leaq " << strMap[this->result] << "(%%" << STR_REG << ")" << ", %%rax\\n\\t\"" << endl;
      store(os, varMap);
      break;
    case Assign:
      loadlhs(os, varMap);
      store(os, varMap);
      break;
    case Power:
      loadlhs(os, varMap);
      try {
        powerCounter = stoi(this->rhs);
        os << "\"movq %%rax, %%rbx\\n\\t\"" << endl;
      } catch (...) {
        os << "\"# Invalid power!\\n\\t\"" << endl;
        powerCounter = 0;
      }
      for (auto i = 0; i < powerCounter; i++)
        os << "\"mulq %%rbx\\n\\t\"" << endl;
      store(os, varMap);
      break;
    default:
      loadlhs(os, varMap);
      loadrhs(os, varMap);
      this->translateOP(os, b);
      store(os, varMap);
      break;
  }
}

void ThreeAd::translateOP(ostream &os, BBlock* b)
{
  switch (this->t) {
    case Addition:        os << "\"addq %%rbx, %%rax\\n\\t\"" << endl; break;
    case Subtraction:     os << "\"subq %%rbx, %%rax\\n\\t\"" << endl; break;
    case Multiplication:  os << "\"mulq %%rbx\\n\\t\"" << endl; break;
    case Division:
      os << "\"movq $0, %%rdx\\n\\t\"" << endl;
      os << "\"divq %%rbx\\n\\t\"" << endl;
      break;
    case Modulo:
      os << "\"movq $0, %%rdx\\n\\t\"" << endl;
      os << "\"divq %%rbx\\n\\t\"" << endl;
      os << "\"movq %%rdx, %%rax\\n\\t\"" << endl;
      break;
    case NotEqual:
      os << "\"cmpq %%rbx, %%rax\\n\\t\"" << endl;
      os << "\"je " << b->falseExit->getLabel() << "\\n\\t\"" << endl;
      break;
    case EqualEqual:
      os << "\"cmpq %%rbx, %%rax\\n\\t\"" << endl;
      os << "\"jne " << b->falseExit->getLabel() << "\\n\\t\"" << endl;
      break;
    case LessThan:
      os << "\"cmpq %%rbx, %%rax\\n\\t\"" << endl;
      os << "\"jge " << b->falseExit->getLabel() << "\\n\\t\"" << endl;
      break;
    case LessOrEqual:
      os << "\"cmpq %%rbx, %%rax\\n\\t\"" << endl;
      os << "\"jg " << b->falseExit->getLabel() << "\\n\\t\"" << endl;
      break;
    case GreaterThan:
      os << "\"cmpq %%rbx, %%rax\\n\\t\"" << endl;
      os << "\"jle " << b->falseExit->getLabel() << "\\n\\t\"" << endl;
      break;
    case GreaterOrEqual:
      os << "\"cmpq %%rbx, %%rax\\n\\t\"" << endl;
      os << "\"jl " << b->falseExit->getLabel() << "\\n\\t\"" << endl;
      break;
    default:
      os << "\"nop\\n\\t\"" << endl;
      break;
  }
}
