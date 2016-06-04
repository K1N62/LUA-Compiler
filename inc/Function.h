#pragma once

#include <string>
#include <iostream>

/** Handles functions
* @author Jim Ahlstrand
*/
class Function : public Node {
public:
  //! Defines types of Function
  enum Type {
      Undefined,
      Name,
      Call,
      Body,
      Param,
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Function();

  /** Constructor with type
  * @param t Type Function type to construct
  */
  Function(Type t);

  //! Default destructor
  virtual ~Function();

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
  //! Function type
  Type type;

};
