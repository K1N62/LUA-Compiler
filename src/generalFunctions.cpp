#include "generalFunctions.h"

//! @remark broken
void garbageCollection()
{
  // Delete functions
  for (auto f : functions)
    delete f;
  // Delete blocks
  for (auto b : blocks)
     delete b;
}

int genVarMap(BBlock* start, map<string, int> &varMap)
{
  set<BBlock*> done, todo;
  todo.insert(start);
  int index = 0;

  while(todo.size() > 0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);

    for (auto &i : *next->getIns()) {
      // Only store if result is not NS (no store)
      if (i.result != "NS"){
        // Add result name if not exists
        if (varMap.find(i.result) == varMap.end()) {
          varMap[i.result] = index;
          index += sizeof(double);
        }
      }
      // Add lhs name if not exists
      if (varMap.find(i.lhs) == varMap.end()) {
        varMap[i.lhs] = index;
        index += sizeof(double);
      }
      // Add rhs name if not exists
      if (varMap.find(i.rhs) == varMap.end()) {
        varMap[i.rhs] = index;
        index += sizeof(double);
      }
    }

    done.insert(next);
    if(next->trueExit != NULL && done.find(next->trueExit) == done.end())
      todo.insert(next->trueExit);
    if(next->falseExit != NULL && done.find(next->falseExit) == done.end())
      todo.insert(next->falseExit);
  }

  return index;
}

int genStrMap(Node* node, map<string, int> &stringMap, string &res, int index)
{
  if (node == NULL)
    return index;

  // Check if node is a string and string isn't already added
  if (node->getType() == "String" && stringMap.find( node->getName() ) == stringMap.end()) {
    stringMap[node->getName()] = index;
    string s = dynamic_cast<Memory*>(node)->getStr();
    res += s + "\\0";
    index += s.size() + 1;
  }

  // Check children
  for (size_t i = 0; i < node->size(); i++) {
    index = genStrMap(node->getChild(i), stringMap, res, index);
  }

  return index;
}

struct classcomp {
  bool operator() (const BBlock* lhs, const BBlock* rhs) const
  {return lhs->id < rhs->id;}
};

void dumpCFG(ostream &os, BBlock* start, Node* root)
{
  // Generate variable map
  map<string, int> varMap;
  genVarMap(start, varMap);

  map<string, int> strMap;
  string s = "";
  genStrMap(root, strMap, s);

  set<BBlock*, classcomp> done, todo;
  // Header
  os << "#include <stdio.h>" << endl << "int main()" << endl << "{" << endl;

  // Variable declaration
  os << "static double var[" << varMap.size() << "] = {0};" << endl;
  os << "static double intbuf[1]   = {0};" << endl;
  os << "static char   str[]       = \"" << s << "\";" << endl;
  os << "static char   printInt[]  = \"%d\\n\";" << endl;
  os << "static char   printStr[]  = \"%s\\n\";" << endl;
  os << "static char   writeInt[]  = \"%d\";" << endl;
  os << "static char   writeStr[]  = \"%s\";" << endl;
  os << "static char   readInt[]   = \"%d\";" << endl;

  // start asm
  os << "asm(" << endl;

  // Load variable array
  os << "\"leaq %[var], %% " << VAR_REG << "\\n\\t\"" << endl;
  os << "\"leaq %[str], %% " << STR_REG << "\\n\\t\"" << endl;

  // Add jump to skip functions
  os << "\"jmp lbl0\\n\\t\"" << endl;

  // Dump functions
  for (auto f : functions)
  {
    map<string, int> funcVarMap;
    genVarMap(f, funcVarMap);

    set<BBlock*> fdone, ftodo;
    todo.insert(f);
    while(todo.size()>0)
    {
      auto first = todo.begin();
      BBlock *next = *first;
      todo.erase(first);

      next->dump(os, funcVarMap, strMap);

      done.insert(next);
      if(next->trueExit!=NULL && done.find(next->trueExit)==done.end())
        todo.insert(next->trueExit);
      if(next->falseExit!=NULL && done.find(next->falseExit)==done.end())
        todo.insert(next->falseExit);
    }
  }

  todo.insert(start);

  // Dump blocks
  while(todo.size() > 0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);

    next->dump(os, varMap, strMap);

    done.insert(next);
    if(next->trueExit != NULL && done.find(next->trueExit) == done.end())
      todo.insert(next->trueExit);
    if(next->falseExit != NULL && done.find(next->falseExit) == done.end())
      todo.insert(next->falseExit);
  }

  // End asm
  os << ": [var]      \"+g\" (var)," << endl;
  os << "  [intbuf]   \"+g\" (intbuf)," << endl;
  os << "  [str]      \"+g\" (str)," << endl;
  os << "  [printInt] \"+g\" (printInt)," << endl;
  os << "  [printStr] \"+g\" (printStr)," << endl;
  os << "  [writeInt] \"+g\" (writeInt)," << endl;
  os << "  [writeStr] \"+g\" (writeStr)," << endl;
  os << "  [readInt]  \"+g\" (readInt)" << endl;
  os << ":" << endl;
  os << ": \"rax\"," << endl;
  os << "  \"rbx\"," << endl;
  os << "  \"rcx\"," << endl;
  os << "  \"rdx\"," << endl;
  os << "  \"rdi\"," << endl;
  os << "  \"rsi\"," << endl;
  os << "  \"al\"," << endl;
  os << "  \"bl\"," << endl;
  os << "  \"r15\"," << endl;
  os << "  \"r14\"" << endl;
  os << ");" << endl;

  // End main
  os << "}" << endl;

  // print varmap for debug
  if (debug) {
    cout << endl;
    cout << "\tVAR MAP (variable name : offset)" << endl;
    for (auto const &var : varMap) {
        cout << "\t" << var.first << "\t: " << var.second << endl;
    }
    cout << endl << endl;
  }
  // print strmap for debug
  if (debug) {
    cout << "\tSTR MAP (string name : offset)" << endl;
    for (auto const &var : strMap) {
        cout << "\t" << var.first << "\t: " << var.second << endl;
    }
    cout << endl;
  }
}

void printCFG(BBlock* start, ofstream& file)
{
  set<BBlock*> done, todo;
  todo.insert(start);

  for (auto f : functions)
  {
    set<BBlock*> fdone, ftodo;
    todo.insert(f);
    while(todo.size()>0)
    {
      auto first = todo.begin();
      BBlock *next = *first;
      todo.erase(first);

      next->print(file);

      done.insert(next);
      if(next->trueExit!=NULL && done.find(next->trueExit)==done.end())
        todo.insert(next->trueExit);
      if(next->falseExit!=NULL && done.find(next->falseExit)==done.end())
        todo.insert(next->falseExit);
    }
  }

  while(todo.size()>0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);

    next->print(file);

    done.insert(next);
    if(next->trueExit!=NULL && done.find(next->trueExit)==done.end())
      todo.insert(next->trueExit);
    if(next->falseExit!=NULL && done.find(next->falseExit)==done.end())
      todo.insert(next->falseExit);
  }
}
