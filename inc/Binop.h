#pragma once

#include "Node.h"
#include "math.h"
#include <cstring>

/** Handles binary operations
* @author Jim Ahlstrand
* @todo add test for number of children, binop can have max 2
*/
class Binop : public Node {
public:
  //! Defines types of Binops
  enum Type {
    Undefined,
    Assign,
    Addition,
    Subtraction,
    Division,
    Multiplication,
    Power,
    Modulo
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Binop();
  /** Constructor with type
  * @param type Binop type of enum Type
  */
  Binop(Type type);

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
  //! Binop type
  Type type;
};
