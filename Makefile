
# Programs
LD 		= g++
CC 		= g++
AR		= ar

# Folders
LIB				= lib
SRC 			= src
BIN 			= bin
OBJ				= obj
INC 			= inc
DOC 			= doc
PROG			= $(BIN)/compiler

# Flags
LDFLAGS		=
CFLAGS 		= -c -g -std=c++11 -Wall -m64 -L$(LIB) -I$(INC)

LEX				= scanner
BISON 		= parser

# Utils
RM 				= /bin/rm
MKDIR 		= /bin/mkdir

# Files
SOURCES 	= $(wildcard $(SRC)/*.cpp)
OBJECTS 	= $(addprefix $(OBJ)/,$(notdir $(SOURCES:.cpp=.o)))

# Default behaviour
all: dir libr $(PROG)

# Compile all sources
$(PROG): $(OBJ)/$(BISON).o $(OBJ)/$(LEX).o $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OBJ)/$(LEX).o: $(SRC)/$(LEX).cpp
	$(CC) $(CFLAGS) $< -o $@

$(OBJ)/$(BISON).o: $(SRC)/$(BISON).cpp
	$(CC) $(CFLAGS) $< -o $@

$(SRC)/$(LEX).cpp: flex

$(SRC)/$(BISON).cpp: bison

# create scanner
flex:
	flex -o $(SRC)/$(LEX).cpp --header-file=$(INC)/$(LEX).h $(SRC)/$(LEX).lex

# create parser
bison:
	bison -o $(SRC)/$(BISON).cpp --defines=$(INC)/$(BISON).h $(SRC)/$(BISON).y

# create libraries
libr:

docs:
	doxygen $(DOC)/doxy.conf

# create directories
dir:
	$(MKDIR) -p $(LIB) $(SRC) $(OBJ) $(INC) $(BIN) $(DOC) $(DOC)/html

# clean
clean:
	$(RM) -f $(PROG) $(OBJ)/* $(INC)/$(BISON).h $(INC)/$(LEX).h $(SRC)/$(LEX).cpp $(SRC)/$(BISON).cpp program program.c graph.dot tree.dot tree.pdf controlflow.pdf

graph:
	dot -Tpdf graph.dot -otree.pdf; dot -Tpdf tree.dot -ocontrolflow.pdf; $(RM) -f graph.dot; $(RM) -f tree.dot

compile: all
	./bin/compiler -o program.c data.lua; $(CC) -g -Wall -m64 program.c -o program
