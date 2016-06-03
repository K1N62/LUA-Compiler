#pragma once

#include "Node.h"


	/** Handles memory operations
* @author Jim Ahlstrand
* @todo implement support for float variables and infinite large int
*/
class Memory : public Node {
public:
  //! Defines types of Memory
  enum Type {
      Nil,
      Number,
      String,
      Function,
      Variable,
  };
  //! @todo fix Fieldlist, ex. local and function calls
  // Constructors
  // ---------------------------------------
  //! Default constructor
  //! @remark is assumed to be a field list
  Memory();

	/** Constructor with integer type
  * @param value integer value of the node
  */
  Memory(int value);

	/** Constructor with string type
  * @param value string value of the node
  * @param isConstant Bool Is this string a constant or variable?
  */
  Memory(string value, bool isConstant = false);

	/** Constructor with function type
  * @param func Node* value of the node
  * @param isSoftLink Bool Determines if link to fuction is soft, that is if it shouldn't be handled by destructor
  */
  Memory(Node* func, bool isSoftLink = false);
  //! Default destructor
  virtual ~Memory();

  // Methods
  // ---------------------------------------
	/** Converts the Node to threeAd
  * @param out current BBlock
  * @return void
  */
  BBlock* convert(BBlock* out);

	/** Evaluate string of the Memory
  * @return string value of the node
  */
  std::string evalStr();

	/** Converts type of node to string
  * @return string type of the node
  */
  string getType();

	/** Gets the function pointer
  * @return Node* pointer to the function node
  */
  Node* getFunc() { return this->func; }

	/** Gets the integer value
  * @return integer
  */
  int getInt() { return this->integer; }

	/** Gets the string value
  * @return string
  */
  string getStr() { return this->str; }

	/** Get length of Memory
  * @return unsigned int length of Memory
  * @remark Depends on type
  */
  unsigned int length();

protected:
  // Properties
  // ---------------------------------------
  //! Memory type
  Type type;
  //! Integer value
  int integer;
  //! String value
  string str;
  //! Function pointer
  Node* func;
  //! Is function soft link
  bool isSoftLink;
};
