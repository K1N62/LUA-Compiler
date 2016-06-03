#pragma once

#include "Node.h"

//! Handles test operations
/**
* @author Jim Ahlstrand
* @todo add test for number of children, test can have max 2
*/
class Test : public Node {
public:
  //! Defines types of Tests
  enum Type {
    Undefined,
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
  //! Default constructor
  Test();
  //! Constructor with type
  /**
  * @param type Test type of enum Type
  */
  Test(Type type);

  // Methods
  // ---------------------------------------
  /** Converts the Node to ThreeAd
  * @param out current BBlock
  * @return void
  */
  BBlock* convert(BBlock* out);
  
  /** Converts type of node to string
  * @return string type of the node
  */
  std::string getType();

protected:
  // Properties
  // ---------------------------------------
  //! Test type
  Type type;
};
