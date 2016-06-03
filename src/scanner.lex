%top{
#include "parser.h"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%
"\n"                  ;
[ ]+                  ;
--.*\n                ;
[0-9]+                return yy::parser::make_NUM(yytext);
"="                   return yy::parser::make_EQ();
":"                   return yy::parser::make_COL();
"["                   return yy::parser::make_BRKOPN();
"]"                   return yy::parser::make_BRKCLS();
"("                   return yy::parser::make_PAROPN();
")"                   return yy::parser::make_PARCLS();
"{"                   return yy::parser::make_CUROPN();
"}"                   return yy::parser::make_CURCLS();
";"                   return yy::parser::make_SEMCOL();
","                   return yy::parser::make_COM();
"+"                   return yy::parser::make_PLUS();
"-"                   return yy::parser::make_MINUS();
"*"                   return yy::parser::make_MULT();
"/"                   return yy::parser::make_DIV();
"^"                   return yy::parser::make_POW();
"%"                   return yy::parser::make_MOD();
"<"                   return yy::parser::make_LESS();
">"                   return yy::parser::make_GREAT();
"<="                  return yy::parser::make_LESSEQ();
">="                  return yy::parser::make_GREATEQ();
"=="                  return yy::parser::make_EQEQ();
"~="                  return yy::parser::make_NOTEQ();
"and"                 return yy::parser::make_AND();
"or"                  return yy::parser::make_OR();
"not"                 return yy::parser::make_NOT();
"#"                   return yy::parser::make_HASH();
"in"                  return yy::parser::make_IN();
"nil"                 return yy::parser::make_NIL();
"while"               return yy::parser::make_WHILE();
"for"                 return yy::parser::make_FOR();
"do"                  return yy::parser::make_DO();
"end"                 return yy::parser::make__END();
"if"                  return yy::parser::make_IF();
"else"                return yy::parser::make_ELSE();
"elseif"              return yy::parser::make_ELSEIF();
"then"                return yy::parser::make_THEN();
"return"              return yy::parser::make_RETURN();
"break"               return yy::parser::make_BREAK();
"false"               return yy::parser::make__FALSE();
"true"                return yy::parser::make__TRUE();
"local"               return yy::parser::make_LOCAL();
"until"               return yy::parser::make_UNTIL();
"repeat"              return yy::parser::make_REP();
"function"            return yy::parser::make_FUNC();
"."                   return yy::parser::make_DOT();
".."                  return yy::parser::make_DDOT();
"..."                 return yy::parser::make_TRIDOT();
\"([^"]|\\.)*\"       return yy::parser::make_STR(yytext);
\'([^']|\\.)*\'       return yy::parser::make_STR(yytext);
[a-zA-Z_][a-zA-Z0-9_]*  return yy::parser::make_NAME(yytext);
<<EOF>>               return yy::parser::make_END();
%%
