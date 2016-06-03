#pragma once

#include "Node.h"

/** Handles contitional operations
* @author Jim Ahlstrand
*/
class Condition : public Node {
public:
    //! Defines types of Conditions
    enum Type {
        Undefined,
        If,
    };

    // Constructors
    // ---------------------------------------
    //! Default constructor
    Condition();
    /** Constructor with type
    * @param type Condition type of enum Type
    */
    Condition(Type type);

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
    //! Condition type
    Type type;
};
