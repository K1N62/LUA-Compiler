
/*     LUA Compiler
 *
 *  Author Jim Ahlstrand
 *    Copyright 2016
 *
 *     Version 1.0
 */

// Yes this is super global, tried with macros but want user to control debug
bool debug = false;

#include <string>
#include <iostream>
#include <exception>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "parser.h"
#include "generalFunctions.h"
#include "BBlock.h"

#define GRAPH_PATH    "graph.dot"
#define CFGRAPH_PATH  "tree.dot"

extern Node* root;
extern FILE* yyin; // Dunno how to solve this in c++

using namespace std;

void yy::parser::error(string const&err)
{
  cout << "Invalid input: " << err << endl;
}

/** LUA Compiler main
* @author Jim Ahlstrand
* @version 1.0
*/
int main(int argc, char **argv)
{
  char graphPath[PATH_MAX];
  char cfgraphPath[PATH_MAX];
  char filePath[PATH_MAX];
  char outputPath[PATH_MAX];
  char *gvalue = NULL, *ovalue = NULL;
  int c,e;

  opterr = 0;
  while ((c = getopt (argc, argv, "hdg:o:")) != -1)
    switch (c)
      {
      case 'h':
        cout << "                LUA Compiler" << endl;
        cout << "   Author Jim Ahlstrand (c) 2016 Version 1.0" << endl;
        cout << "" << endl;
        cout << " Usage: compiler [OPTIONS] -o outputfile luafile" << endl;
        cout << "" << endl;
        cout << " -o       Outputfile, stdout is default" << endl;
        cout << " -d       Debug mode, prints debug messages to stdout" << endl;
        cout << " -g       Path to graphs" << endl;
        cout << " -h       Displays this help" << endl;
        return 0;
        break;
      case 'd':
        debug = true;
        break;
      case 'g':
        gvalue = optarg;
        break;
      case 'o':
        ovalue = optarg;
        break;
      case '?':
        if (optopt == 'o')
          cerr << "Option -o requires an argument" << endl;
        else if (optopt == 'g')
          cerr << "Option -g requires an argument" << endl;
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  // Prepare graph path
  if (gvalue != NULL) {
    realpath(gvalue, graphPath);
    realpath(gvalue, cfgraphPath);
    // Add filenames to the paths
    strncat(graphPath, "/", PATH_MAX - strlen(graphPath));
    strncat(cfgraphPath, "/", PATH_MAX - strlen(cfgraphPath));
    strncat(graphPath, GRAPH_PATH, PATH_MAX - strlen(graphPath));
    strncat(cfgraphPath, CFGRAPH_PATH, PATH_MAX - strlen(cfgraphPath));
    if (debug) {
      cout << "Path for graph file: " << graphPath << endl;
      cout << "Path for cfg-graph file: " << graphPath << endl;
    }
  }
  // Prepare output path
  if (ovalue != NULL) {
    realpath(ovalue, outputPath);
    if (debug)
      cout << "Path for output file: " << outputPath << endl;
  }

  // File path
  if (argc > 1) {
    realpath(argv[argc - 1], filePath);
    if (debug)
      cout << "Path for input file: " << filePath << endl;
  } else {
    cerr << "Invalid number of arguments" << endl;
    return 1;
  }

  // Open input
  try {
    yyin = fopen(filePath,"r");
  } catch (exception& e) {
    cerr << "Could not open file: " << e.what() << endl;
    return 1;
  }

  if (yyin != NULL) {
    // Get parser
    yy::parser parser;
    e = parser.parse();

    fclose(yyin);

  } else {
    cerr << "No file open for input" << endl;
    return 1;
  }

  // If no parser errors
  if (e == 0){

    // Open graphs
    ofstream graph;
    ofstream cfgraph;
    if (gvalue != NULL){
      graph.open(graphPath, ios::out);
      cfgraph.open(cfgraphPath, ios::out);
    } else {
      graph.open(GRAPH_PATH, ios::out);
      cfgraph.open(CFGRAPH_PATH, ios::out);
    }

    // Open outputfile
    ofstream of;
    if (ovalue != NULL) {
      of.open(outputPath, ios::out);
    }
    ostream &out = ovalue != NULL ? of : cout;

    if (graph.is_open()) {
      // Print header
      graph << "digraph {" << endl;
      // Print graph
      root->print(graph);
      // Print footer
      graph << "}" << endl;
      //close graph
      graph.close();
    }

    // Convert the tree to three address nodes
    BBlock* block = new BBlock();
    try {
      root->convert(block);
      dumpCFG(out, block, root);
    } catch (exception& e) {
      cerr << "Error: " << e.what() << endl;
    }

    if (cfgraph.is_open()) {
      // Print header
      cfgraph << "digraph {" << endl;
      // Print graph
      printCFG(block, cfgraph);
      // Print footer
      cfgraph << "}" << endl;
      //close graph
      cfgraph.close();
    }

    // Delete root block
    delete block;
  }

  // Delete root node
  delete root;

  //garbageCollection();

  return 0;
}
