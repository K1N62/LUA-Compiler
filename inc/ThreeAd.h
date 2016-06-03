#pragma once

#include <string>
#include <list>
#include <map>

using namespace std;

class BBlock;

class ThreeAd
{
public:
  enum Type {
    Sequence,
    String,
    Assign,
    If,
    ElseIf,
    Equal,
    Addition,
    Subtraction,
    Division,
    Multiplication,
    Modulo,
    Power,
    FuncHead,
    FuncFoot,
    FuncCall,
    Return,
    LessThan,
    LessOrEqual,
    GreaterThan,
    GreaterOrEqual,
    EqualEqual,
    NotEqual,
    And,
    Or,
    Not,
    False,
    True,
  };

  Type t;
  string result, lhs, rhs;

  ThreeAd(string out, string l, string r, Type t);
  ThreeAd(string out, string l, string r, Type t, bool s);
  string getType();

  string dump();
  void translate(ostream &os, BBlock* b, map<string, int> &varMap, map<string, int> &strMap);
  void translateOP(ostream &os, BBlock* b);
  void setString(bool s) { this->isString = s; }

private:
  string  VAR_REG   = "rdi",
          STR_REG   = "rsi",
          TYPE_REG  = "r8",
          TYPE_INT  = "$0x0",
          TYPE_STR  = "$0x1";

  bool isString;
  void loadlhs(ostream &os, map<string, int> &varMap);
  void loadrhs(ostream &os, map<string, int> &varMap);
  void store  (ostream &os, map<string, int> &varMap);

};
