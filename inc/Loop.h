#pragma once

#include "Node.h"

/** Handles loops
* @author Jim Ahlstrand
* @remark "for" loop is rewritten in the parser, however this is not a complete rewrite
*/
class Loop : public Node {
public:
  //! Defines types of Loops
  enum Type {
    Undefined,
    Repeat,
    While,
    loop
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Loop();
  /** Constructor with type
  * @param type Loop type of enum Type
  */
  Loop(Type type);

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
  //! Loop type
  Type type;
};
