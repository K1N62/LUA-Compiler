#pragma once

#include <string>
#include <iostream>
#include "Node.h"

/** Handles functions
* @author Jim Ahlstrand
*/
class Func : public Node {
public:
  //! Defines types of Func
  enum Type {
      Name,
      Call,
      Body,
      Param,
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Func();

  /** Constructor with type
  * @param t Type Func type to construct
  */
  Func(Type t);

  //! Default destructor
  virtual ~Func();

  // Methods
  // ---------------------------------------
	/** Converts the Node to threeAd
  * @param out current BBlock
  * @return void
  */
  BBlock* convert(BBlock* out);

	/** Converts type of node to string
  * @return string Type of the node
  */
  string getType();


protected:
  // Properties
  // ---------------------------------------
  //! Func type
  Type type;

};
