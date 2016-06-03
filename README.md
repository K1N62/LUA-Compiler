# LUA-Compiler
![Build Status](https://travis-ci.org/K1N62/LUA-Compiler.svg?branch=master)

A not so fully featured compiler for LUA

##Install
Build the project with
`make`

To run the compiler use
`./bin/compiler [OPTIONS] path/to/lua/file`
For help user on using the compiler
`./bin/compiler -h`

To create the parse three and control flow graph you need [graphviz](http://www.graphviz.org/) installed, then
`make graph`

To create the docs you need [doxygen](http://www.stack.nl/~dimitri/doxygen/) installed, then
`make docs`
