#pragma once

#include <set>
#include "BBlock.h"
#include "ThreeAd.h"
#include "Node.h"
#include "Memory.h"

int genVarMap(BBlock* b, map<string, int> &varMap);
int genStrMap(Node* root, map<string, int> &stringMap, string &res, int index = 0);
void dumpCFG(ostream &os, BBlock* start, Node* root);
void printCFG(BBlock* start, ofstream& file);
void garbageCollection();
