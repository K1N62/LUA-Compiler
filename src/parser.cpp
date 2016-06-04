// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "src/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.

#line 51 "src/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 15 "src/parser.y" // lalr1.cc:408

  #include <string>
  #include <iostream>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;


#line 63 "src/parser.cpp" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 130 "src/parser.cpp" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 54: // chunk
      case 55: // block
      case 56: // stat
      case 57: // laststat
      case 58: // funcname
      case 59: // funcbody
      case 60: // varlist
      case 61: // var
      case 62: // namelist
      case 63: // explist
      case 64: // exp
      case 65: // prefixexp
      case 66: // functioncall
      case 67: // args
      case 68: // function
      case 69: // parlist
      case 70: // tableconstructor
      case 71: // fieldlist
      case 72: // field
      case 73: // fieldsep
      case 74: // rep_func_name
      case 75: // rep_var
      case 76: // rep_list_name
      case 77: // rep_exp
      case 78: // rep_elseif
      case 79: // rep_stat
      case 80: // rep_field
      case 81: // opt_explist
      case 82: // opt_parlist
      case 83: // opt_name
      case 84: // opt_tridot
      case 85: // opt_fieldlist
      case 86: // opt_fieldsep
      case 87: // opt_semi
      case 88: // opt_laststat
      case 89: // opt_exp
      case 90: // opt_else
      case 91: // opt_eq
        value.move< Node* > (that.value);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 54: // chunk
      case 55: // block
      case 56: // stat
      case 57: // laststat
      case 58: // funcname
      case 59: // funcbody
      case 60: // varlist
      case 61: // var
      case 62: // namelist
      case 63: // explist
      case 64: // exp
      case 65: // prefixexp
      case 66: // functioncall
      case 67: // args
      case 68: // function
      case 69: // parlist
      case 70: // tableconstructor
      case 71: // fieldlist
      case 72: // field
      case 73: // fieldsep
      case 74: // rep_func_name
      case 75: // rep_var
      case 76: // rep_list_name
      case 77: // rep_exp
      case 78: // rep_elseif
      case 79: // rep_stat
      case 80: // rep_field
      case 81: // opt_explist
      case 82: // opt_parlist
      case 83: // opt_name
      case 84: // opt_tridot
      case 85: // opt_fieldlist
      case 86: // opt_fieldsep
      case 87: // opt_semi
      case 88: // opt_laststat
      case 89: // opt_exp
      case 90: // opt_else
      case 91: // opt_eq
        value.copy< Node* > (that.value);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 54: // chunk
      case 55: // block
      case 56: // stat
      case 57: // laststat
      case 58: // funcname
      case 59: // funcbody
      case 60: // varlist
      case 61: // var
      case 62: // namelist
      case 63: // explist
      case 64: // exp
      case 65: // prefixexp
      case 66: // functioncall
      case 67: // args
      case 68: // function
      case 69: // parlist
      case 70: // tableconstructor
      case 71: // fieldlist
      case 72: // field
      case 73: // fieldsep
      case 74: // rep_func_name
      case 75: // rep_var
      case 76: // rep_list_name
      case 77: // rep_exp
      case 78: // rep_elseif
      case 79: // rep_stat
      case 80: // rep_field
      case 81: // opt_explist
      case 82: // opt_parlist
      case 83: // opt_name
      case 84: // opt_tridot
      case 85: // opt_fieldlist
      case 86: // opt_fieldsep
      case 87: // opt_semi
      case 88: // opt_laststat
      case 89: // opt_exp
      case 90: // opt_else
      case 91: // opt_eq
        yylhs.value.build< Node* > ();
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        yylhs.value.build< string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 49 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 627 "src/parser.cpp" // lalr1.cc:847
    break;

  case 3:
#line 51 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                  if (yystack_[0].value.as< Node* > () != NULL )
                    yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                  root = yylhs.value.as< Node* > ();
                }
#line 638 "src/parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 60 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 644 "src/parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 64 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Binop(Binop::Type::Assign);
                  yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 654 "src/parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 70 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 660 "src/parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 72 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());	}
#line 666 "src/parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 74 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Loop(Loop::Type::While);
                  Node* t = new Node(Node::Type::Test);
                  t->addChild(yystack_[3].value.as< Node* > ());
                  t->addChild(yystack_[1].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(t);
                }
#line 678 "src/parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 82 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Loop(Loop::Type::Repeat);
                  Node* t = new Node(Node::Type::Test);
                  t->setTestFirst(false);
                  t->addChild(yystack_[0].value.as< Node* > ());
                  t->addChild(yystack_[2].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(t);
                }
#line 691 "src/parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 91 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Condition(Condition::Type::If);
                  Node* t = new Node(Node::Type::Test);
                  t->addChild(yystack_[5].value.as< Node* > ());
                  t->addChild(yystack_[3].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(t);
                  if (yystack_[2].value.as< Node* > ()->size() != 0) {
                    yystack_[2].value.as< Node* > ()->transferChildren(yylhs.value.as< Node* > ());
                    delete yystack_[2].value.as< Node* > ();
                  }
                  if (yystack_[1].value.as< Node* > () != NULL )
                    yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                }
#line 709 "src/parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 105 "src/parser.y" // lalr1.cc:847
    {
                  // Rewrites to an while loop, does not
                  // support negative increments though
                  yylhs.value.as< Node* > () = new Node(Node::Type::Stat);

                  Node* eq = new Binop(Binop::Type::Assign);
                  eq->addChild(new Memory(yystack_[8].value.as< string > ()));
                  eq->addChild(yystack_[6].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(eq);

                  Node* less = new Test(Test::Type::LessOrEqual);
                  less->addChild(new Memory(yystack_[8].value.as< string > ()));
                  less->addChild(yystack_[4].value.as< Node* > ());

                  Node* t = new Node(Node::Type::Test);
                  t->addChild(less);

                  Node* w = new Loop(Loop::Type::While);
                  w->addChild(t);

                  Node* add = new Binop(Binop::Type::Addition);
                  add->addChild(new Memory(yystack_[8].value.as< string > ()));
                  if (yystack_[3].value.as< Node* > () != NULL )
                  add->addChild(yystack_[3].value.as< Node* > ());
                  else
                  add->addChild(new Memory(1));

                  eq = new Binop(Binop::Type::Assign);
                  eq->addChild(new Memory(yystack_[8].value.as< string > ()));
                  eq->addChild(add);

                  yystack_[1].value.as< Node* > ()->addChild(eq);

                  t->addChild(yystack_[1].value.as< Node* > ());

                  yylhs.value.as< Node* > ()->addChild(w);
                }
#line 751 "src/parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 143 "src/parser.y" // lalr1.cc:847
    { exit(1); }
#line 757 "src/parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 145 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Binop(Binop::Type::Assign);
                  yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                  dynamic_cast<Memory*>(yystack_[0].value.as< Node* > ())->getFunc()->setFuncname(yystack_[1].value.as< Node* > ()->evalStr());
                }
#line 768 "src/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 152 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Node(Node::Type::FunctionBody);
                  yylhs.value.as< Node* > ()->setLocal(true);
                  yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[1].value.as< string > ()));
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->setFuncname(yystack_[1].value.as< string > ());
                }
#line 780 "src/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 160 "src/parser.y" // lalr1.cc:847
    {
                  // Assumes only one name
                  yylhs.value.as< Node* > () = new Binop(Binop::Type::Assign);
                  yystack_[1].value.as< Node* > ()->getChild(0)->setLocal(true);
                  yystack_[1].value.as< Node* > ()->transferChildren(yylhs.value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                  delete yystack_[1].value.as< Node* > ();
                }
#line 793 "src/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 171 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Node(Node::Type::Return);
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 802 "src/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 176 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 808 "src/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 180 "src/parser.y" // lalr1.cc:847
    {
                  if (yystack_[1].value.as< Node* > ()->size() == 0) {
                    yylhs.value.as< Node* > () = new Memory(yystack_[2].value.as< string > ());
                  } else {
                  	yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                    yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[2].value.as< string > ()));
                  }
	                if (yystack_[0].value.as< Node* > () != NULL )
	                	yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 823 "src/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 193 "src/parser.y" // lalr1.cc:847
    {
                  Node* f = new Node(Node::Type::FunctionBody);
                  if (yystack_[3].value.as< Node* > () != NULL ) {
                    yystack_[3].value.as< Node* > ()->reverse();
                    Node* p = new Node(Node::Type::FunctionParam);
                    p->addChild(yystack_[3].value.as< Node* > ());
                    f->addChild(p);
                  }
                  f->addChild(yystack_[1].value.as< Node* > ());
                  yylhs.value.as< Node* > () = new Memory(f);
                }
#line 839 "src/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 207 "src/parser.y" // lalr1.cc:847
    {
                  if (yystack_[0].value.as< Node* > ()->size() == 0) {
                    yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                  } else {
                    yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > ();
                    yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                  }
                }
#line 852 "src/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 218 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory(yystack_[0].value.as< string > ()); }
#line 858 "src/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 220 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Node(Node::Type::FieldElement);
                  yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                }
#line 868 "src/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 226 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Memory(yystack_[0].value.as< string > ());
                  //$$ = new Node(Node::Type::MemberFunction);
                  //$$->addChild($1);
                  //$$->addChild(new Memory($3));
                }
#line 879 "src/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 235 "src/parser.y" // lalr1.cc:847
    {
                  if (yystack_[0].value.as< Node* > ()->size() > 0) {
                    yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > ();
                    yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[1].value.as< string > ()));
                  } else {
                    yylhs.value.as< Node* > () = new Node(Node::Type::ListName);
                    yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[1].value.as< string > ()));
                  }
                }
#line 893 "src/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 247 "src/parser.y" // lalr1.cc:847
    {
                  if (yystack_[1].value.as< Node* > ()->size() != 0) {
                    yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                    yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                  } else {
                    yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > ();
                  }
                }
#line 906 "src/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 258 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory("Nil"); }
#line 912 "src/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 260 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::False); }
#line 918 "src/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 262 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::True); }
#line 924 "src/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 264 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory(stoi(yystack_[0].value.as< string > ())); }
#line 930 "src/parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 266 "src/parser.y" // lalr1.cc:847
    {
                  yystack_[0].value.as< string > ().erase(0,1);
                  yystack_[0].value.as< string > ().erase(yystack_[0].value.as< string > ().length() - 1, 1);
                  yylhs.value.as< Node* > () = new Memory(yystack_[0].value.as< string > (), true);
                }
#line 940 "src/parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 272 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory("...", true); }
#line 946 "src/parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 274 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 952 "src/parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 276 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 958 "src/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 278 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 964 "src/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 280 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::DoubleDot); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 970 "src/parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 282 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Addition); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 976 "src/parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 284 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Subtraction); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 982 "src/parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 286 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Division); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 988 "src/parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 288 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Multiplication); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 994 "src/parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 290 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Power); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1000 "src/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 292 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Modulo); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1006 "src/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 294 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::LessThan); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1012 "src/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 296 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::LessOrEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1018 "src/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 298 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::GreaterThan); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1024 "src/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 300 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::GreaterOrEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1030 "src/parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 302 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::EqualEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1036 "src/parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 304 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::NotEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1042 "src/parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 306 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::And); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1048 "src/parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 308 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::Or); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1054 "src/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 310 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::Not); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1060 "src/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 312 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Negate); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1066 "src/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 314 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Hash); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1072 "src/parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 318 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1078 "src/parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 320 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1084 "src/parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 322 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1090 "src/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 326 "src/parser.y" // lalr1.cc:847
    {
                  // Split up multiple argument lists into several calls
                  if (yystack_[0].value.as< Node* > () != NULL) {
                    if (yystack_[0].value.as< Node* > ()->getType() == "ExpressionList" && yystack_[0].value.as< Node* > ()->size() > 1) {
                      yylhs.value.as< Node* > () = new Node(Node::Type::Stat);
                      for (unsigned int i = 0; i < yystack_[0].value.as< Node* > ()->size(); i++) {
                        Node* c = new Node(Node::Type::FunctionCall);
                        c->addChild(new Memory(yystack_[1].value.as< Node* > ()->evalStr()));
                        c->addChild(yystack_[0].value.as< Node* > ()->getChild(i));
                        yylhs.value.as< Node* > ()->addChild(c);
                      }
                      delete yystack_[1].value.as< Node* > ();
                    } else {
                      yylhs.value.as< Node* > () = new Node(Node::Type::FunctionCall);
                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                    }
                  } else {
                    yylhs.value.as< Node* > () = new Node(Node::Type::FunctionCall);
                    yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                  }
                }
#line 1117 "src/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 349 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = yystack_[3].value.as< Node* > ();
                  yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[1].value.as< string > ()));
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 1127 "src/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 357 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1133 "src/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 359 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1139 "src/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 361 "src/parser.y" // lalr1.cc:847
    {
                  yystack_[0].value.as< string > ().erase(0,1);
                  yystack_[0].value.as< string > ().erase(yystack_[0].value.as< string > ().length() - 1, 1);
                  yylhs.value.as< Node* > () = new Node(Node::Type::ExpressionList);
                  yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[0].value.as< string > (), true));
                }
#line 1150 "src/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 370 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1156 "src/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 374 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                  if (yystack_[0].value.as< Node* > () != NULL )
                    yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 1166 "src/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 380 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Tridot); }
#line 1172 "src/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 384 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1178 "src/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 388 "src/parser.y" // lalr1.cc:847
    {
                  if (yystack_[1].value.as< Node* > ()->size() != 0) {
                    yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                    yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                    yylhs.value.as< Node* > ()->moveToFront();
                  } else {
                    yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > ();
                  }
                }
#line 1192 "src/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 400 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Binop(Binop::Type::Assign);
                  yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 1202 "src/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 406 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = new Binop(Binop::Type::Assign);
                  yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[2].value.as< string > ()));
                  yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                }
#line 1212 "src/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 412 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1218 "src/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 416 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1224 "src/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 418 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1230 "src/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 422 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::FunctionName); }
#line 1236 "src/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 424 "src/parser.y" // lalr1.cc:847
    {
              	   yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[0].value.as< string > ()));
              	}
#line 1244 "src/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 430 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::VariableList); }
#line 1250 "src/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 432 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1256 "src/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 436 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::ListName); }
#line 1262 "src/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 438 "src/parser.y" // lalr1.cc:847
    {
              	   yylhs.value.as< Node* > ()->addChild(new Memory(yystack_[0].value.as< string > ()));
              	}
#line 1270 "src/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 444 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::ExpressionList); }
#line 1276 "src/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 446 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ()); }
#line 1282 "src/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 450 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Condition(Condition::Type::If); }
#line 1288 "src/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 452 "src/parser.y" // lalr1.cc:847
    {
                  yylhs.value.as< Node* > () = yystack_[4].value.as< Node* > ();
                  Node* t = new Node(Node::Type::Test);
                  t->addChild(yystack_[2].value.as< Node* > ());
                  t->addChild(yystack_[0].value.as< Node* > ());
                  yylhs.value.as< Node* > ()->addChild(t);
                }
#line 1300 "src/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 462 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Stat); }
#line 1306 "src/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 464 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ()); }
#line 1312 "src/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 468 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory(); }
#line 1318 "src/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 470 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1324 "src/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 474 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1330 "src/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 476 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1336 "src/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 480 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1342 "src/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 482 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1348 "src/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 486 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1354 "src/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 488 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory(yystack_[0].value.as< string > ()); }
#line 1360 "src/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 492 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1366 "src/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 494 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Tridot); }
#line 1372 "src/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 498 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Memory(); }
#line 1378 "src/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 500 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1384 "src/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 504 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1390 "src/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 506 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1396 "src/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 510 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1402 "src/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 512 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1408 "src/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 516 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1414 "src/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 518 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1420 "src/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 522 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1426 "src/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 524 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1432 "src/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 528 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1438 "src/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 530 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1444 "src/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 534 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1450 "src/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 536 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1456 "src/parser.cpp" // lalr1.cc:847
    break;


#line 1460 "src/parser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -50;

  const signed char parser::yytable_ninf_ = -86;

  const short int
  parser::yypact_[] =
  {
       6,    29,   216,   -50,   -50,    27,    10,    31,    27,   105,
     -50,     9,     5,    27,    41,    32,    32,    35,   -14,   126,
     215,   -50,   -50,   -50,   -50,   -50,   -50,   -50,    21,    43,
      27,    27,    27,   -50,    96,   126,   -50,   -50,   -50,    39,
      58,   -50,    66,   151,   -50,    27,   -50,   -50,    79,    84,
      81,   329,   -50,    43,   -50,   -50,   -50,   -50,    88,   -50,
     104,   109,    27,    85,   -50,   -50,    95,    27,   346,   -50,
     -50,    87,    15,   -50,   -30,    72,    72,    31,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    98,   -50,   -50,   101,   219,    43,
     -50,   -50,    27,   -50,    42,   -50,   -50,     3,   -50,     2,
     290,    93,    27,   311,   -16,   -50,   -50,   106,   -50,    94,
     113,   362,   377,   386,   386,   386,   386,   386,   386,   386,
     -30,   -30,    72,    72,    72,    72,   244,   141,   142,   -50,
     -50,   -50,   -50,   346,   144,   150,   -50,    55,   -50,   -50,
     -50,   346,   132,   -50,   -50,    21,   -50,   128,   -50,    31,
     -50,    27,   -50,    31,    71,   -50,   -50,    27,   -50,   -50,
     143,   269,   145,    31,    27,   147,   346,   -50,    27,   157,
     -50,   -50,   168,   -50,   346,    31,   101,   149,   -50,   -50
  };

  const unsigned char
  parser::yydefact_[] =
  {
      81,     0,    99,     1,    21,     0,     0,    81,     0,    77,
      17,     0,    81,     0,     0,    97,    97,     0,    53,     0,
       6,     3,    30,    29,    27,    28,    26,    31,    93,     0,
       0,     0,     0,    53,     0,    33,    54,    32,    34,    75,
       0,     4,     0,     0,    86,     0,    16,    75,     0,   105,
       0,     0,    71,     0,    98,    82,   100,    77,    20,    60,
       0,     0,     0,    77,    56,    59,    21,     0,    68,    94,
      83,     0,    87,    61,    51,    50,    52,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    77,     7,    81,    25,     0,
      77,    15,     0,    55,    89,    13,     5,     0,    23,     0,
       0,     0,     0,     0,    95,    64,    63,    91,    88,     0,
       0,    49,    48,    42,    44,    43,    45,    46,    47,    35,
      36,    37,    39,    38,    41,    40,     0,     0,     0,    79,
      78,    14,   106,     9,     0,     0,    18,    53,    57,    22,
      58,    67,     0,    70,    69,    96,    65,     0,    62,    81,
       8,     0,    76,    81,   103,    72,    90,     0,    84,    92,
       0,   101,     0,    81,     0,     0,    66,    19,     0,     0,
      12,   104,     0,    10,   102,    81,    81,     0,    80,    11
  };

  const short int
  parser::yypgoto_[] =
  {
     -50,   167,   -12,   -50,   -50,   -50,   -49,   -50,    -1,    -8,
     -34,     8,     0,   166,    61,   -50,   -50,    -7,   -50,    16,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   114,   -50,
     -50,   -50,   -50,   -50,   156,   -50,   -50,   -50,   -50
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    41,    42,    15,    16,    53,    73,    17,    33,    40,
      44,    68,    35,    36,    64,    37,   118,    38,    69,    70,
     155,   104,    58,    94,    45,   164,     2,   114,    46,   119,
     146,   158,    71,   156,    55,    21,   179,   175,   101
  };

  const short int
  parser::yytable_[] =
  {
      50,    18,    19,    49,   105,    59,    -2,   153,     4,   154,
     -73,   -73,    65,    34,    47,    39,    43,    89,    90,    91,
      47,    51,    92,   106,    22,    23,    66,    -2,    65,     3,
      22,    23,     4,    63,    13,    28,    24,    25,    74,    75,
      76,    26,    24,    25,    48,   116,    52,    26,    -2,    67,
     141,    27,    13,    98,    28,    54,    29,    27,    13,    57,
      28,   138,    29,    93,   117,   120,   142,    30,   144,   145,
     110,    31,    32,    30,    72,   113,    95,    31,    32,   -74,
     -74,   173,   174,    96,    99,   139,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    65,   102,    77,   -85,   147,    19,   100,   108,
     143,    -2,    -2,   107,   109,   -85,   -85,   -85,    -2,   112,
     151,   115,   -85,   137,    92,   150,   159,   -85,   -85,    59,
     160,   157,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   162,   170,    92,   165,
     163,   172,    60,    61,    62,   166,   167,    63,   169,    28,
     177,   181,   180,    97,   183,   185,   189,     1,    20,   171,
     148,   168,    56,   187,   188,   176,     0,   111,     0,     0,
     186,     0,   182,     0,     0,     0,   184,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,    92,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   -54,     0,
      92,     4,     5,     6,     7,     8,     0,     0,     0,     9,
      10,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,   -54,   -54,   -54,   140,     0,     0,    13,   -54,     0,
       0,    14,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   161,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   178,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   149,
       0,    92,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     152,     0,    92,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   103,     0,    92,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,    92,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,    92,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,    92,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,    92,
      86,    87,    88,    89,    90,    91,     0,     0,    92
  };

  const short int
  parser::yycheck_[] =
  {
      12,     2,     2,    11,    53,     3,     0,    23,     5,    25,
      24,    25,    19,     5,     5,     5,     8,    47,    48,    49,
       5,    13,    52,    57,     3,     4,     5,    22,    35,     0,
       3,     4,     5,    31,    31,    33,    15,    16,    30,    31,
      32,    20,    15,    16,    35,    30,     5,    20,    17,    28,
      99,    30,    31,    45,    33,    23,    35,    30,    31,    24,
      33,    95,    35,    24,    72,    77,   100,    46,    26,    27,
      62,    50,    51,    46,    31,    67,    18,    50,    51,    24,
      25,    10,    11,    17,     5,    97,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   109,    22,     8,     0,   107,   107,    24,     5,
     102,    10,    11,    25,     5,    10,    11,    32,    17,    24,
     112,    34,    17,    25,    52,    32,    32,    22,    23,     3,
      17,    25,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     5,   159,    52,     5,
       8,   163,    26,    27,    28,     5,    24,    31,    30,    33,
      17,   173,    17,    12,    17,     8,    17,     0,     2,   161,
     109,   155,    16,   185,   186,   167,    -1,    63,    -1,    -1,
      12,    -1,   174,    -1,    -1,    -1,   178,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     3,    -1,
      52,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,
      -1,    26,    27,    28,    25,    -1,    -1,    31,    33,    -1,
      -1,    35,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    25,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    25,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    29,
      -1,    52,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      29,    -1,    52,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    32,    -1,    52,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    52,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    52,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      44,    45,    46,    47,    48,    49,    -1,    -1,    52
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    54,    79,     0,     5,     6,     7,     8,     9,    13,
      14,    19,    21,    31,    35,    56,    57,    60,    61,    65,
      66,    88,     3,     4,    15,    16,    20,    30,    33,    35,
      46,    50,    51,    61,    64,    65,    66,    68,    70,     5,
      62,    54,    55,    64,    63,    77,    81,     5,    35,    62,
      55,    64,     5,    58,    23,    87,    87,    24,    75,     3,
      26,    27,    28,    31,    67,    70,     5,    28,    64,    71,
      72,    85,    31,    59,    64,    64,    64,     8,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    52,    24,    76,    18,    17,    12,    64,     5,
      24,    91,    22,    32,    74,    59,    63,    25,     5,     5,
      64,    81,    24,    64,    80,    34,    30,    62,    69,    82,
      55,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    25,    63,    55,
      25,    59,    63,    64,    26,    27,    83,    61,    67,    29,
      32,    64,    29,    23,    25,    73,    86,    25,    84,    32,
      17,    25,     5,     8,    78,     5,     5,    24,    72,    30,
      55,    64,    55,    10,    11,    90,    64,    17,    25,    89,
      17,    55,    64,    17,    64,     8,    12,    55,    55,    17
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    53,    54,    54,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    59,
      60,    61,    61,    61,    62,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      67,    68,    69,    69,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     3,     1,     3,     5,     4,
       7,    10,     7,     3,     4,     3,     2,     1,     3,     5,
       2,     1,     4,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     1,     1,     3,     2,     4,     3,     1,
       1,     2,     2,     1,     3,     3,     5,     3,     1,     1,
       1,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       5,     0,     3,     0,     3,     0,     1,     0,     1,     0,
       2,     0,     2,     0,     1,     0,     1,     0,     1,     0,
       2,     0,     2,     0,     2,     0,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "STR", "NUM", "NAME", "WHILE",
  "FOR", "DO", "IF", "ELSE", "ELSEIF", "THEN", "RETURN", "BREAK", "_FALSE",
  "_TRUE", "_END", "IN", "LOCAL", "NIL", "REP", "UNTIL", "SEMCOL", "EQ",
  "COM", "DOT", "COL", "BRKOPN", "BRKCLS", "TRIDOT", "PAROPN", "PARCLS",
  "CUROPN", "CURCLS", "FUNC", "OR", "AND", "LESS", "GREAT", "LESSEQ",
  "GREATEQ", "EQEQ", "NOTEQ", "DDOT", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "NOT", "HASH", "POW", "$accept", "chunk", "block", "stat",
  "laststat", "funcname", "funcbody", "varlist", "var", "namelist",
  "explist", "exp", "prefixexp", "functioncall", "args", "function",
  "parlist", "tableconstructor", "fieldlist", "field", "fieldsep",
  "rep_func_name", "rep_var", "rep_list_name", "rep_exp", "rep_elseif",
  "rep_stat", "rep_field", "opt_explist", "opt_parlist", "opt_name",
  "opt_tridot", "opt_fieldlist", "opt_fieldsep", "opt_semi",
  "opt_laststat", "opt_exp", "opt_else", "opt_eq", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    49,    49,    50,    59,    63,    69,    71,    73,    81,
      90,   104,   142,   144,   151,   159,   170,   175,   179,   192,
     206,   217,   219,   225,   234,   246,   257,   259,   261,   263,
     265,   271,   273,   275,   277,   279,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     309,   311,   313,   317,   319,   321,   325,   348,   356,   358,
     360,   369,   373,   379,   383,   387,   399,   405,   411,   415,
     417,   422,   423,   430,   431,   436,   437,   444,   445,   450,
     451,   462,   463,   468,   469,   474,   475,   480,   481,   486,
     487,   492,   493,   498,   499,   504,   505,   510,   511,   516,
     517,   522,   523,   528,   529,   534,   535
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2006 "src/parser.cpp" // lalr1.cc:1155
