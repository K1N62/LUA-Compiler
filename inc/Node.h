#pragma once

#define TRUE            1
#define FALSE           0
#define LEFT            this->children[0]
#define RIGHT           this->children[1]

// Includes
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <map>
#include "Error.h"

using namespace std;

extern bool debug;
extern unsigned int nameCounter;

class Memory;
class BBlock;

/** Builds a tree-node structure
* @author Jim Ahlstrand
* @todo move function to seperate class
*/
class Node {
public:
  //! Defines types of Nodes
  //! @todo implement local functions and namelists
  enum Type {
    Undefined,
    ExpressionList,     //! @todo Implement this
    VariableList,       //! @todo Implement this
    FunctionName,
    FunctionCall,
    FunctionBody,
    FunctionParam,
    MemberFunction,     //! @todo Implement this
    ListName,           //! @todo Implement this
    Stat,
    Field,              //! @todo Implement this
    FieldElement,       //! @todo Implement this
    DoubleDot,          //! @todo Implement this
    Hash,
    Negate,             //! @todo Implement this
    Tridot,             //! @todo Implement this
    Return,
    Do,                 //! @todo Implement this
    Test,               //! @remark should be restructured, moved to testclass?
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Node();
  /** Constructor with type
  * @param type Node type of enum Type
  */
  Node(Type type);
  //! Default destructor
  virtual ~Node();

  // Methods
  // ---------------------------------------
  /** Prints the node tree
  * @param id integer of currently highest node id
  * @param file ofstream file handler
  * @return id integer of this node id
  */
  void print(ofstream& file);

  /** Adds a child to the node
  * @param child Node child to add
  * @return 0 on success else error
  */
  void addChild(Node* child) { this->children.push_back(child); }

  /** Get a child of the node
  * @param i unsigned integer index of child
  * @return Node
  */
  Node* getChild(unsigned int i);

  /** Reorders tha children in reverse
  * @return void
  */
  void reverse() { std::reverse(this->children.begin(), this->children.end()); }

  /** Transfers children to parent
  * @param parent Node* pointer to the parent node
  * @return Node
  */
  void transferChildren(Node* parent);

  /** Moves the end element to the front
  * @return int 0 on success
  * @remark ugly hack only used for field list correction
  */
  int moveToFront();

  /** Get the node id
  * @return id integer of nodes id
  */
  int getNodeID() { return this->id; }

  /** Get node locality
  * @return bool True if node is local
  */
  inline bool getLocal() { return this->local; }

  /** Get name of node
  * @return string name of the node
  */
  inline string getName() { return this->name; }

  /** Set name of node
  * @param n string new name of node
  * @return void
  */
  inline void setName( string n ) { this->name = n; }

  /** Set funcname of node
  * @param f string new funcname of node
  * @return void
  */
  inline void setFuncname( string f ) { this->funcname = f; }

  /** Set locality value
  * @param l bool new value of local
  * @return bool True if node is local
  */
  inline void setLocal( bool l ) { this->local = l; }

  /** Is this node undefined?
  * @return bool true if node is undefined
  */
  inline bool isUndefined() { return this->type == Undefined ? true : false; }

  /** Is this node a leaf node?
  * @return bool true if node is leaf
  */
  inline bool isLeaf() { return this->children.size() == 0; }

  /** Returns the number of childs in this node
  * @return id integer number of childs
  */
  inline unsigned int size() { return this->children.size(); }

  /** Converts the Node to threeAd
  * @param out BBlock* current BBlock
  * @return void
  */
  virtual BBlock* convert(BBlock* out);

  /** Evaluate string value of the Node
  * @return string value of the node
  */
  virtual string evalStr() { return ""; }

  /** Converts type of node to string
  * @return string type of the node
  */
  virtual string getType();

  //! Set testFirst value
  /**
  * @param bool b testFirst value
  * @return void
  */
  void setTestFirst(bool b) { this->testFirst = b; }

protected:
  // Properties
  // ---------------------------------------
  //! Test before or after execute?
  bool testFirst;
  //! Node id
  int id;
  //! Localy defined
  bool local;
  //! Name of the node, auto generated
  string name;
  //! Name of the function associated with the function body, uglyhack
  string funcname;
  //! Node type
  Type type;
  //! The children connected to the node
  vector<Node*> children;
};
