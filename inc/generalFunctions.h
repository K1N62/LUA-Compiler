
/** Collection of general functions
 * @author Jim Ahlstrand
 */

#pragma once

#include <set>
#include "BBlock.h"
#include "ThreeAd.h"
#include "Node.h"
#include "Memory.h"

/** Gernate variable map
 * This function maps variables and node ids to an index
 * @param b BBlock* block to start variable search
 * @param varmap map Map of variable name and index
 * @return integer Last index
 */
int genVarMap(BBlock* b, map<string, int> &varMap);

/** Gernate string map
 * This function maps strings to an index recursively
 * @param root Node* node to start string search
 * @param stringMap map Map of strings and index
 * @param res string All strings concatenated into one with nullbyte seperation
 * @param index int Latest index
 * @return integer Last index
 */
int genStrMap(Node* root, map<string, int> &stringMap, string &res, int index = 0);

/** Dump control flow in assembly
 * @param os ostream Outputstream, can be a file or stdout
 * @param start BBlock* Block to start from also used for genVarMap
 * @param root Node* Node to start from, used by genStrMap
 * @return void
 */
void dumpCFG(ostream &os, BBlock* start, Node* root);

/** Print control flow in dot format
 * @param start BBlock* Block to start from
 * @param file ofstream File output handle
 * @return void
 */
void printCFG(BBlock* start, ofstream& file);

/** Handles deletion of blocks
 * This function is broken and should be replaced to fix memoryleaks
 * @return void
 */
void garbageCollection();
