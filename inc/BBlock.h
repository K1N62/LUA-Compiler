#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ThreeAd.h"
using namespace std;

extern int labelCounter;
extern bool debug;
extern vector<BBlock*> functions;
extern vector<BBlock*> blocks;

string newLabel();

/** Handles Basic blocks
* @author Jim Ahlstrand
*/
class BBlock
{
public:
  // Constructors
  // ---------------------------------------
  //! Default constructor
  BBlock();
  //! Default destructor
  virtual ~BBlock();

  // Methods
  // ---------------------------------------
  /** Translates and prints the block content to outstream
  * @param os ostream Outstream to print to
  * @param varMap map Map of variables and their offset
  * @param strMao map Map of strings and their offset
  * @return void
  */
  void dump(ostream &os, map<string, int> &varMap, map<string, int> &strMap);

  /** Prints the block content in dot format
  * @param file ofstream File to print to
  * @return void
  */
  void print(ofstream& file);

  /** Adds an instruction to the block
  * @param ins ThreeAd New instruction to add
  * @return void
  */
  void addIns(ThreeAd ins);

  /** Get block label
  * @return string Label of the block
  */
  inline string getLabel() { return this->label; }

  /** Get block size
  * @return string Label of the block
  */
  inline int size() { return this->instructions.size(); }

  /** Set block label
  * @param l string New label to set
  * @return void
  */
  inline void setLabel(string l) { this->label = l; }

  /** Get all instruction from the block
  * @return constant pointer to ThreeAd list
  */
  inline const list<ThreeAd>* getIns() { return &(this->instructions); }

  /** Mark this block for garbageCollection
  * @return void
  */
  inline void mark() { blocks.push_back(this); }

protected:
  //! Blocks instructions
  list<ThreeAd> instructions;
  //! Label of the block
  string label;

public:
  //! True and False exit guidance for control flow
  BBlock *trueExit, *falseExit;
  //! The block id
  int id;
};
