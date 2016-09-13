#pragma once

#include <string>
#include <list>
#include <map>

#define VAR_REG "r15"
#define STR_REG "r14"

using namespace std;

class BBlock;

/** Handles three address code translation
* @author Jim Ahlstrand
*/
class ThreeAd
{
public:
  //! Defines types of ThreeAd
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
    FuncCallHead,
    FuncCallFoot,
    FuncCallParam,
    FuncCall,
    FuncParam,
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

  // Constructors
  // ---------------------------------------
  /** Constructor with basic properties
   * @param out string Three address result
   * @param l string Three address left hand side
   * @param r string Three address tight hand side
   * @param t Type type of ThreeAd
   */
  ThreeAd(string out, string l, string r, Type t);

  /** Constructor with basic properties and string flag set
   * @param out string Three address result
   * @param l string Three address left hand side
   * @param r string Three address tight hand side
   * @param t Type type of ThreeAd
   * @param s bool String flag
   */
  ThreeAd(string out, string l, string r, Type t, bool s);

  // Methods
  // ---------------------------------------
  /** Get type
   * @return string Type of ThreeAd
   */
  string getType();

  /** Get the string representation of the ThreeAd
   * @return string ThreeAd as a string
   */
  string dump();

  /** Translates the three address into assembly
   * @param os ostream Output stream, can be a file or stdout
   * @param b BBlock* current block address is in
   * @param varMap map Map of varible names and their index
   * @param strMap map Map of strings and their index
   * @return void
   */
  void translate(ostream &os, BBlock* b, map<string, int> &varMap, map<string, int> &strMap);

  /** Set string flag
   * @param s bool New flag value
   * @return void
   */
  void setString(bool s) { this->isString = s; }

private:
  //! Type of ThreeAd
  Type t;
  //! Is string flag
  bool isString;

  /** Translates an operation, part of translate()
   * @param os ostream Output stream
   * @param b BBlock* Current working block
   */
  void translateOP(ostream &os, BBlock* b);

  /** Loads the left hand side into rax
   * @param os ostream Output stream
   * @param varMap map Map of varible names and their index
   */
  void loadlhs(ostream &os, map<string, int> &varMap);

  /** Loads the right hand side into rbx
   * @param os ostream Output stream
   * @param varMap map Map of varible names and their index
   */
  void loadrhs(ostream &os, map<string, int> &varMap);

  /** Saves the result from rax
   * @param os ostream Output stream
   * @param varMap map Map of varible names and their index
   */
  void store(ostream &os, map<string, int> &varMap);

  /** Loads a parameter to correct register
   * @param os ostream Output stream
   * @param varMap map Map of varible names and their index
   * @param i int Parameter index
   */
  void setparam(ostream &os, map<string, int> &varMap, int i);

public:
  //! result, left hand side, right hand side
  string result, lhs, rhs;
};
