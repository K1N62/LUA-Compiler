// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file inc/parser.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_INC_PARSER_H_INCLUDED
# define YY_YY_INC_PARSER_H_INCLUDED
// //                    "%code requires" blocks.
#line 6 "src/parser.y" // lalr1.cc:372

  #include "Node.h"
  #include "Test.h"
  #include "Loop.h"
  #include "Binop.h"
  #include "Memory.h"
  #include "Condition.h"
  using namespace std;

#line 54 "inc/parser.h" // lalr1.cc:372


# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"


#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 130 "inc/parser.h" // lalr1.cc:372



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // chunk
      // block
      // stat
      // laststat
      // funcname
      // funcbody
      // varlist
      // var
      // namelist
      // explist
      // exp
      // prefixexp
      // functioncall
      // args
      // function
      // parlist
      // tableconstructor
      // fieldlist
      // field
      // fieldsep
      // rep_func_name
      // rep_var
      // rep_list_name
      // rep_exp
      // rep_elseif
      // rep_stat
      // rep_field
      // opt_explist
      // opt_parlist
      // opt_name
      // opt_tridot
      // opt_fieldlist
      // opt_fieldsep
      // opt_semi
      // opt_laststat
      // opt_exp
      // opt_else
      // opt_eq
      char dummy1[sizeof(Node*)];

      // STR
      // NUM
      // NAME
      char dummy2[sizeof(string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        STR = 258,
        NUM = 259,
        NAME = 260,
        WHILE = 261,
        FOR = 262,
        DO = 263,
        IF = 264,
        ELSE = 265,
        ELSEIF = 266,
        THEN = 267,
        RETURN = 268,
        BREAK = 269,
        _FALSE = 270,
        _TRUE = 271,
        _END = 272,
        IN = 273,
        LOCAL = 274,
        NIL = 275,
        REP = 276,
        UNTIL = 277,
        SEMCOL = 278,
        EQ = 279,
        COM = 280,
        DOT = 281,
        COL = 282,
        BRKOPN = 283,
        BRKCLS = 284,
        TRIDOT = 285,
        PAROPN = 286,
        PARCLS = 287,
        CUROPN = 288,
        CURCLS = 289,
        FUNC = 290,
        OR = 291,
        AND = 292,
        LESS = 293,
        GREAT = 294,
        LESSEQ = 295,
        GREATEQ = 296,
        EQEQ = 297,
        NOTEQ = 298,
        DDOT = 299,
        PLUS = 300,
        MINUS = 301,
        MULT = 302,
        DIV = 303,
        MOD = 304,
        NOT = 305,
        HASH = 306,
        POW = 307
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t);

  basic_symbol (typename Base::kind_type t, const Node* v);

  basic_symbol (typename Base::kind_type t, const string v);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END ();

    static inline
    symbol_type
    make_STR (const string& v);

    static inline
    symbol_type
    make_NUM (const string& v);

    static inline
    symbol_type
    make_NAME (const string& v);

    static inline
    symbol_type
    make_WHILE ();

    static inline
    symbol_type
    make_FOR ();

    static inline
    symbol_type
    make_DO ();

    static inline
    symbol_type
    make_IF ();

    static inline
    symbol_type
    make_ELSE ();

    static inline
    symbol_type
    make_ELSEIF ();

    static inline
    symbol_type
    make_THEN ();

    static inline
    symbol_type
    make_RETURN ();

    static inline
    symbol_type
    make_BREAK ();

    static inline
    symbol_type
    make__FALSE ();

    static inline
    symbol_type
    make__TRUE ();

    static inline
    symbol_type
    make__END ();

    static inline
    symbol_type
    make_IN ();

    static inline
    symbol_type
    make_LOCAL ();

    static inline
    symbol_type
    make_NIL ();

    static inline
    symbol_type
    make_REP ();

    static inline
    symbol_type
    make_UNTIL ();

    static inline
    symbol_type
    make_SEMCOL ();

    static inline
    symbol_type
    make_EQ ();

    static inline
    symbol_type
    make_COM ();

    static inline
    symbol_type
    make_DOT ();

    static inline
    symbol_type
    make_COL ();

    static inline
    symbol_type
    make_BRKOPN ();

    static inline
    symbol_type
    make_BRKCLS ();

    static inline
    symbol_type
    make_TRIDOT ();

    static inline
    symbol_type
    make_PAROPN ();

    static inline
    symbol_type
    make_PARCLS ();

    static inline
    symbol_type
    make_CUROPN ();

    static inline
    symbol_type
    make_CURCLS ();

    static inline
    symbol_type
    make_FUNC ();

    static inline
    symbol_type
    make_OR ();

    static inline
    symbol_type
    make_AND ();

    static inline
    symbol_type
    make_LESS ();

    static inline
    symbol_type
    make_GREAT ();

    static inline
    symbol_type
    make_LESSEQ ();

    static inline
    symbol_type
    make_GREATEQ ();

    static inline
    symbol_type
    make_EQEQ ();

    static inline
    symbol_type
    make_NOTEQ ();

    static inline
    symbol_type
    make_DDOT ();

    static inline
    symbol_type
    make_PLUS ();

    static inline
    symbol_type
    make_MINUS ();

    static inline
    symbol_type
    make_MULT ();

    static inline
    symbol_type
    make_DIV ();

    static inline
    symbol_type
    make_MOD ();

    static inline
    symbol_type
    make_NOT ();

    static inline
    symbol_type
    make_HASH ();

    static inline
    symbol_type
    make_POW ();


    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 438,     ///< Last index in yytable_.
      yynnts_ = 39,  ///< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 53  ///< Number of tokens.
    };


  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
    };
    const unsigned int user_token_number_max_ = 307;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
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
        value.copy< Node* > (other.value);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.copy< string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
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
        value.copy< Node* > (v);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.copy< string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Node* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
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
        value.template destroy< Node* > ();
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.template destroy< string > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
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
        value.move< Node* > (s.value);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.move< string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_END ()
  {
    return symbol_type (token::END);
  }

  parser::symbol_type
  parser::make_STR (const string& v)
  {
    return symbol_type (token::STR, v);
  }

  parser::symbol_type
  parser::make_NUM (const string& v)
  {
    return symbol_type (token::NUM, v);
  }

  parser::symbol_type
  parser::make_NAME (const string& v)
  {
    return symbol_type (token::NAME, v);
  }

  parser::symbol_type
  parser::make_WHILE ()
  {
    return symbol_type (token::WHILE);
  }

  parser::symbol_type
  parser::make_FOR ()
  {
    return symbol_type (token::FOR);
  }

  parser::symbol_type
  parser::make_DO ()
  {
    return symbol_type (token::DO);
  }

  parser::symbol_type
  parser::make_IF ()
  {
    return symbol_type (token::IF);
  }

  parser::symbol_type
  parser::make_ELSE ()
  {
    return symbol_type (token::ELSE);
  }

  parser::symbol_type
  parser::make_ELSEIF ()
  {
    return symbol_type (token::ELSEIF);
  }

  parser::symbol_type
  parser::make_THEN ()
  {
    return symbol_type (token::THEN);
  }

  parser::symbol_type
  parser::make_RETURN ()
  {
    return symbol_type (token::RETURN);
  }

  parser::symbol_type
  parser::make_BREAK ()
  {
    return symbol_type (token::BREAK);
  }

  parser::symbol_type
  parser::make__FALSE ()
  {
    return symbol_type (token::_FALSE);
  }

  parser::symbol_type
  parser::make__TRUE ()
  {
    return symbol_type (token::_TRUE);
  }

  parser::symbol_type
  parser::make__END ()
  {
    return symbol_type (token::_END);
  }

  parser::symbol_type
  parser::make_IN ()
  {
    return symbol_type (token::IN);
  }

  parser::symbol_type
  parser::make_LOCAL ()
  {
    return symbol_type (token::LOCAL);
  }

  parser::symbol_type
  parser::make_NIL ()
  {
    return symbol_type (token::NIL);
  }

  parser::symbol_type
  parser::make_REP ()
  {
    return symbol_type (token::REP);
  }

  parser::symbol_type
  parser::make_UNTIL ()
  {
    return symbol_type (token::UNTIL);
  }

  parser::symbol_type
  parser::make_SEMCOL ()
  {
    return symbol_type (token::SEMCOL);
  }

  parser::symbol_type
  parser::make_EQ ()
  {
    return symbol_type (token::EQ);
  }

  parser::symbol_type
  parser::make_COM ()
  {
    return symbol_type (token::COM);
  }

  parser::symbol_type
  parser::make_DOT ()
  {
    return symbol_type (token::DOT);
  }

  parser::symbol_type
  parser::make_COL ()
  {
    return symbol_type (token::COL);
  }

  parser::symbol_type
  parser::make_BRKOPN ()
  {
    return symbol_type (token::BRKOPN);
  }

  parser::symbol_type
  parser::make_BRKCLS ()
  {
    return symbol_type (token::BRKCLS);
  }

  parser::symbol_type
  parser::make_TRIDOT ()
  {
    return symbol_type (token::TRIDOT);
  }

  parser::symbol_type
  parser::make_PAROPN ()
  {
    return symbol_type (token::PAROPN);
  }

  parser::symbol_type
  parser::make_PARCLS ()
  {
    return symbol_type (token::PARCLS);
  }

  parser::symbol_type
  parser::make_CUROPN ()
  {
    return symbol_type (token::CUROPN);
  }

  parser::symbol_type
  parser::make_CURCLS ()
  {
    return symbol_type (token::CURCLS);
  }

  parser::symbol_type
  parser::make_FUNC ()
  {
    return symbol_type (token::FUNC);
  }

  parser::symbol_type
  parser::make_OR ()
  {
    return symbol_type (token::OR);
  }

  parser::symbol_type
  parser::make_AND ()
  {
    return symbol_type (token::AND);
  }

  parser::symbol_type
  parser::make_LESS ()
  {
    return symbol_type (token::LESS);
  }

  parser::symbol_type
  parser::make_GREAT ()
  {
    return symbol_type (token::GREAT);
  }

  parser::symbol_type
  parser::make_LESSEQ ()
  {
    return symbol_type (token::LESSEQ);
  }

  parser::symbol_type
  parser::make_GREATEQ ()
  {
    return symbol_type (token::GREATEQ);
  }

  parser::symbol_type
  parser::make_EQEQ ()
  {
    return symbol_type (token::EQEQ);
  }

  parser::symbol_type
  parser::make_NOTEQ ()
  {
    return symbol_type (token::NOTEQ);
  }

  parser::symbol_type
  parser::make_DDOT ()
  {
    return symbol_type (token::DDOT);
  }

  parser::symbol_type
  parser::make_PLUS ()
  {
    return symbol_type (token::PLUS);
  }

  parser::symbol_type
  parser::make_MINUS ()
  {
    return symbol_type (token::MINUS);
  }

  parser::symbol_type
  parser::make_MULT ()
  {
    return symbol_type (token::MULT);
  }

  parser::symbol_type
  parser::make_DIV ()
  {
    return symbol_type (token::DIV);
  }

  parser::symbol_type
  parser::make_MOD ()
  {
    return symbol_type (token::MOD);
  }

  parser::symbol_type
  parser::make_NOT ()
  {
    return symbol_type (token::NOT);
  }

  parser::symbol_type
  parser::make_HASH ()
  {
    return symbol_type (token::HASH);
  }

  parser::symbol_type
  parser::make_POW ()
  {
    return symbol_type (token::POW);
  }



} // yy
#line 1596 "inc/parser.h" // lalr1.cc:372




#endif // !YY_YY_INC_PARSER_H_INCLUDED
