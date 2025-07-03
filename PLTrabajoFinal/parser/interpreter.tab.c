/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "interpreter.y"

#include <iostream>
#include <string>

/*******************************************/
/* NEW in example 5 */
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* NEW in example 6 */
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  NEW in example 16
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* NEW in example 7 */
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

/* NEW in example 15 */
#include "../table/logicalVariable.hpp"

/*******************************************/
/* NEW in example 11 */
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 15 */
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 13 */
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 14 */
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
/* NEW in example 10 */
#include "../table/init.hpp"
/*******************************************/

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();


extern int lineNumber; //!< External line counter


/* NEW in example 15 */
extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* New in example 17 */
extern int control; //!< External: to control the interactive mode in "if" and "while" sentences 




/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/* NEW in example 6 */
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/
/* NEW in example 7 */
extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/
/* NEW in example 16 */
extern lp::AST *root; //!< External root of the abstract syntax tree AST


#line 191 "interpreter.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "interpreter.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COLON = 4,                      /* COLON  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_READ = 6,                       /* READ  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_THEN = 8,                       /* THEN  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_ENDIF = 10,                     /* ENDIF  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_ENDWHILE = 12,                  /* ENDWHILE  */
  YYSYMBOL_CLEAR = 13,                     /* CLEAR  */
  YYSYMBOL_PLACE = 14,                     /* PLACE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_FROM = 16,                      /* FROM  */
  YYSYMBOL_TO = 17,                        /* TO  */
  YYSYMBOL_STEP = 18,                      /* STEP  */
  YYSYMBOL_ENDFOR = 19,                    /* ENDFOR  */
  YYSYMBOL_SWITCH = 20,                    /* SWITCH  */
  YYSYMBOL_CASE = 21,                      /* CASE  */
  YYSYMBOL_DEFAULT = 22,                   /* DEFAULT  */
  YYSYMBOL_ENDSWITCH = 23,                 /* ENDSWITCH  */
  YYSYMBOL_READ_STR = 24,                  /* READ_STR  */
  YYSYMBOL_LETFCURLYBRACKET = 25,          /* LETFCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 26,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_REPEAT = 27,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 28,                     /* UNTIL  */
  YYSYMBOL_DO = 29,                        /* DO  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_ASSIGNMENT = 31,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_NUMBER = 33,                    /* NUMBER  */
  YYSYMBOL_BOOL = 34,                      /* BOOL  */
  YYSYMBOL_VARIABLE = 35,                  /* VARIABLE  */
  YYSYMBOL_UNDEFINED = 36,                 /* UNDEFINED  */
  YYSYMBOL_CONSTANT = 37,                  /* CONSTANT  */
  YYSYMBOL_BUILTIN = 38,                   /* BUILTIN  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_GREATER_OR_EQUAL = 41,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 42,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 43,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 44,                 /* LESS_THAN  */
  YYSYMBOL_EQUAL = 45,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 46,                 /* NOT_EQUAL  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_PLUS = 48,                      /* PLUS  */
  YYSYMBOL_MINUS = 49,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 50,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 51,                  /* DIVISION  */
  YYSYMBOL_MODULO = 52,                    /* MODULO  */
  YYSYMBOL_FLOOR_DIVISION = 53,            /* FLOOR_DIVISION  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_CONCATENATION = 56,             /* CONCATENATION  */
  YYSYMBOL_PLUS_EQUAL = 57,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 58,               /* MINUS_EQUAL  */
  YYSYMBOL_MULTIPLICATION_EQUAL = 59,      /* MULTIPLICATION_EQUAL  */
  YYSYMBOL_DIVISION_EQUAL = 60,            /* DIVISION_EQUAL  */
  YYSYMBOL_UNARY = 61,                     /* UNARY  */
  YYSYMBOL_POWER = 62,                     /* POWER  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_stmtlist = 65,                  /* stmtlist  */
  YYSYMBOL_switchlist = 66,                /* switchlist  */
  YYSYMBOL_stmt = 67,                      /* stmt  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_controlSymbol = 69,             /* controlSymbol  */
  YYSYMBOL_if = 70,                        /* if  */
  YYSYMBOL_while = 71,                     /* while  */
  YYSYMBOL_cond = 72,                      /* cond  */
  YYSYMBOL_for = 73,                       /* for  */
  YYSYMBOL_switch = 74,                    /* switch  */
  YYSYMBOL_case = 75,                      /* case  */
  YYSYMBOL_asgn = 76,                      /* asgn  */
  YYSYMBOL_print = 77,                     /* print  */
  YYSYMBOL_read = 78,                      /* read  */
  YYSYMBOL_clear = 79,                     /* clear  */
  YYSYMBOL_place = 80,                     /* place  */
  YYSYMBOL_exp = 81,                       /* exp  */
  YYSYMBOL_listOfExp = 82,                 /* listOfExp  */
  YYSYMBOL_repeat = 83,                    /* repeat  */
  YYSYMBOL_restOfListOfExp = 84            /* restOfListOfExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   249,   249,   263,   268,   291,   302,   307,   317,   322,
     327,   332,   338,   344,   350,   356,   362,   368,   374,   379,
     387,   395,   403,   414,   427,   439,   445,   455,   466,   476,
     486,   497,   503,   510,   515,   519,   523,   527,   531,   538,
     545,   552,   557,   563,   571,   581,   587,   593,   599,   605,
     611,   617,   623,   629,   635,   640,   645,   651,   657,   664,
     711,   717,   723,   729,   735,   741,   747,   753,   759,   765,
     775,   780,   790,   800,   805
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COLON",
  "PRINT", "READ", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "ENDWHILE",
  "CLEAR", "PLACE", "FOR", "FROM", "TO", "STEP", "ENDFOR", "SWITCH",
  "CASE", "DEFAULT", "ENDSWITCH", "READ_STR", "LETFCURLYBRACKET",
  "RIGHTCURLYBRACKET", "REPEAT", "UNTIL", "DO", "STRING", "ASSIGNMENT",
  "COMMA", "NUMBER", "BOOL", "VARIABLE", "UNDEFINED", "CONSTANT",
  "BUILTIN", "OR", "AND", "GREATER_OR_EQUAL", "LESS_OR_EQUAL",
  "GREATER_THAN", "LESS_THAN", "EQUAL", "NOT_EQUAL", "NOT", "PLUS",
  "MINUS", "MULTIPLICATION", "DIVISION", "MODULO", "FLOOR_DIVISION",
  "LPAREN", "RPAREN", "CONCATENATION", "PLUS_EQUAL", "MINUS_EQUAL",
  "MULTIPLICATION_EQUAL", "DIVISION_EQUAL", "UNARY", "POWER", "$accept",
  "program", "stmtlist", "switchlist", "stmt", "block", "controlSymbol",
  "if", "while", "cond", "for", "switch", "case", "asgn", "print", "read",
  "clear", "place", "exp", "listOfExp", "repeat", "restOfListOfExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,     3,   205,   -65,   -65,   -65,   -50,   -44,   -65,   -65,
     -65,   -23,   -11,   -65,   -21,   -65,   -65,   -12,    10,   -65,
     -65,   -65,   -65,   -65,   -65,    40,    41,    46,   -65,   -65,
     -65,    82,     5,    -3,    -3,    82,    34,    -2,    19,   288,
     -65,   533,    82,    82,    82,    82,   533,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,     1,    82,    82,    82,    82,   549,
       2,    20,    82,    48,    47,   480,    82,    82,    22,   -65,
     315,   -12,    10,   -65,   669,   669,   669,   669,   669,   -65,
     669,    82,   751,    16,    16,   573,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
     -65,    82,    82,   -65,   -65,   597,   -65,   -65,    82,   151,
     621,   -65,    -3,   505,    26,   -65,   692,   714,   736,   736,
     736,   736,   736,   736,   -30,   -30,   -54,   -54,   -54,   -54,
      16,    16,   -65,   263,   348,   645,    82,   -65,    79,    82,
     -65,   -65,   -65,   -65,   -65,   -65,    54,    14,   -65,   505,
     381,    82,   -65,   -65,    80,   -65,   -65,   -65,   -65,   455,
     -65,    82,   -65,   -65,   406,   121,   431,   -65,   -65,   -65,
     -65,   456,   230,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     5,     8,     0,     0,    21,    21,
      43,     0,     0,    21,     0,     3,    21,     0,     0,     4,
      14,    12,    13,    16,    17,     0,     0,     0,    18,    19,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     9,    10,    11,
      69,    45,    57,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,    57,    58,    32,    31,    35,    36,    37,    38,    34,
      33,    70,    68,    51,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    40,    41,     0,     3,     3,     0,     0,
       0,    42,     0,    73,     0,    50,    67,    66,    61,    63,
      60,    62,    64,    65,    46,    47,    48,    49,    53,    54,
      55,    56,    25,     0,     0,     0,     0,     6,     0,     0,
      71,    59,     3,    22,    24,    44,     0,     0,    72,    73,
       0,     0,    21,    21,     0,    28,     7,    74,    23,     0,
       3,     0,     3,    21,     0,     0,     0,     3,    27,     3,
      29,     0,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -15,   -65,   -65,   -65,    -4,   -65,   -65,   -33,
     -65,   -65,   -65,   -35,   -65,   -65,   -65,   -65,   -28,   -65,
     -65,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   147,    19,    20,    33,    21,    22,    63,
      23,    24,   156,    25,    26,    27,    28,    29,    59,   114,
      30,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    64,   101,     3,    31,    34,    73,    65,   102,    37,
      32,    79,    40,    74,    75,    76,    77,    78,    80,    41,
      96,    97,    98,    99,    36,    70,   101,    82,    83,    84,
      85,    35,   102,    38,   105,   153,   154,   155,   109,   110,
      60,    46,    61,    47,    48,    42,    43,    44,    45,    49,
      66,    62,    67,   113,    68,    81,   106,   103,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   151,   130,   131,   104,   107,   111,   102,   138,
     135,   141,   148,   152,   162,   157,     0,     0,     0,     0,
       0,   133,   134,    86,    87,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,    97,    98,    99,   146,     0,
     101,   149,    50,     0,     0,    51,   102,    52,     0,    53,
      54,     0,     0,   159,     0,   169,     0,   150,     0,    55,
      56,    57,     0,   165,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,   166,   160,   161,
       0,     0,   171,     0,   172,     0,     0,     0,     0,   167,
      86,    87,    88,    89,    90,    91,    92,    93,   136,    94,
      95,    96,    97,    98,    99,     0,     0,   101,     0,     0,
       0,     0,     0,   102,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
      95,    96,    97,    98,    99,    -2,     4,   101,     5,     0,
       6,     7,     8,   102,     0,     0,     9,     0,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,    14,
      15,     4,    16,     5,     0,     6,     7,     8,     0,     0,
      17,     9,    18,    10,    11,    12,     0,     0,     0,     0,
      13,   -30,   -30,   -30,    14,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     4,    17,     5,    18,     6,     7,
       8,     0,   142,   143,     9,     0,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,    14,    15,     4,
      16,     5,     0,     6,     7,     8,     0,     0,    17,     9,
      18,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,    14,    15,    69,    16,     4,     0,     5,     0,
       6,     7,     8,    17,     0,    18,     9,     0,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,    14,
      15,     0,    16,   112,     0,     0,     0,     0,     0,     4,
      17,     5,    18,     6,     7,     8,     0,     0,     0,     9,
     144,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
       0,     0,     4,    17,     5,    18,     6,     7,     8,     0,
       0,   158,     9,     0,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,    14,    15,     4,    16,     5,
       0,     6,     7,     8,     0,     0,    17,     9,    18,    10,
      11,    12,     0,     0,     0,   168,    13,     0,     0,     0,
      14,    15,     4,    16,     5,     0,     6,     7,     8,     0,
       0,    17,     9,    18,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,   170,    14,    15,     4,    16,     5,
       0,     6,     7,     8,     0,     0,    17,     9,    18,    10,
      11,    12,     0,     0,     0,   173,    13,     0,     0,     0,
      14,    15,     0,    16,   163,     0,     0,     0,     0,     0,
       0,    17,     0,    18,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    96,    97,    98,    99,     0,
       0,   101,   108,     0,     0,     0,     0,   102,     0,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,    98,    99,     0,     0,   101,   139,     0,     0,
       0,     0,   102,     0,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    96,    97,    98,    99,     0,
       0,   101,     0,    50,     0,     0,    51,   102,    71,     0,
      72,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,     0,     0,     0,     0,    58,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    96,
      97,    98,    99,     0,   100,   101,     0,     0,     0,     0,
       0,   102,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,    95,    96,    97,    98,    99,     0,   115,   101,
       0,     0,     0,     0,     0,   102,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,    95,    96,    97,    98,
      99,     0,   132,   101,     0,     0,     0,     0,     0,   102,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
      95,    96,    97,    98,    99,     0,   137,   101,     0,     0,
       0,     0,     0,   102,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    96,    97,    98,    99,     0,
     145,   101,     0,     0,     0,     0,     0,   102,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    96,
      97,    98,    99,     0,     0,   101,     0,     0,     0,     0,
       0,   102,    87,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,    98,    99,     0,     0,   101,     0,
       0,     0,     0,     0,   102,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,    97,    98,    99,     0,     0,
     101,     0,     0,     0,     0,     0,   102,   -31,   -31,   -31,
     -31,   -31,   -31,     0,    94,    95,    96,    97,    98,    99,
       0,     0,   101,     0,     0,     0,     0,     0,   102,    94,
      95,    96,    97,    98,    99,     0,     0,   101,     0,     0,
       0,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      15,    34,    56,     0,    54,     9,    41,    35,    62,    13,
      54,    46,    16,    41,    42,    43,    44,    45,    46,    31,
      50,    51,    52,    53,    35,    40,    56,    55,    56,    57,
      58,    54,    62,    54,    62,    21,    22,    23,    66,    67,
      35,    31,    37,     3,     3,    57,    58,    59,    60,     3,
      16,    54,    54,    81,    35,    54,     8,    55,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    18,   101,   102,    55,    29,    55,    62,   112,
     108,    55,     3,    29,     4,   149,    -1,    -1,    -1,    -1,
      -1,   106,   107,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,   136,    -1,
      56,   139,    30,    -1,    -1,    33,    62,    35,    -1,    37,
      38,    -1,    -1,   151,    -1,     4,    -1,   142,    -1,    47,
      48,    49,    -1,   161,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,   162,   152,   153,
      -1,    -1,   167,    -1,   169,    -1,    -1,    -1,    -1,   163,
      39,    40,    41,    42,    43,    44,    45,    46,    17,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,     0,     1,    56,     3,    -1,
       5,     6,     7,    62,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,     1,    27,     3,    -1,     5,     6,     7,    -1,    -1,
      35,    11,    37,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    35,     3,    37,     5,     6,
       7,    -1,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,     1,
      27,     3,    -1,     5,     6,     7,    -1,    -1,    35,    11,
      37,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    26,    27,     1,    -1,     3,    -1,
       5,     6,     7,    35,    -1,    37,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,     1,
      35,     3,    37,     5,     6,     7,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    35,     3,    37,     5,     6,     7,    -1,
      -1,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,     1,    27,     3,
      -1,     5,     6,     7,    -1,    -1,    35,    11,    37,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    25,     1,    27,     3,    -1,     5,     6,     7,    -1,
      -1,    35,    11,    37,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,     1,    27,     3,
      -1,     5,     6,     7,    -1,    -1,    35,    11,    37,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    25,    -1,    27,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    32,    -1,    -1,    -1,    -1,    62,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    32,    -1,    -1,
      -1,    -1,    62,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    30,    -1,    -1,    33,    62,    35,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    62,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    62,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    62,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    62,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    62,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    62,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    62,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    62,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,     1,     3,     5,     6,     7,    11,
      13,    14,    15,    20,    24,    25,    27,    35,    37,    67,
      68,    70,    71,    73,    74,    76,    77,    78,    79,    80,
      83,    54,    54,    69,    69,    54,    35,    69,    54,    65,
      69,    31,    57,    58,    59,    60,    31,     3,     3,     3,
      30,    33,    35,    37,    38,    47,    48,    49,    54,    81,
      35,    37,    54,    72,    72,    81,    16,    54,    35,    26,
      65,    35,    37,    76,    81,    81,    81,    81,    81,    76,
      81,    54,    81,    81,    81,    81,    39,    40,    41,    42,
      43,    44,    45,    46,    48,    49,    50,    51,    52,    53,
      55,    56,    62,    55,    55,    81,     8,    29,    32,    81,
      81,    55,    28,    81,    82,    55,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    55,    65,    65,    81,    17,    55,    72,    32,
      84,    55,     9,    10,    12,    55,    81,    66,     3,    81,
      65,    18,    29,    21,    22,    23,    75,    84,    10,    81,
      69,    69,     4,    29,    65,    81,    65,    69,    19,     4,
      23,    65,    65,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    69,    70,    70,    71,    72,    73,    73,    74,    74,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      78,    78,    78,    79,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     0,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     6,     8,     6,     3,    12,    10,     7,    10,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     1,     6,     1,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       0,     2,     6,     0,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmtlist  */
#line 250 "interpreter.y"
                  { 
		    // Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog); 

			// End of parsing
			//	return 1;
		  }
#line 1783 "interpreter.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 263 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.stmts) = new std::list<lp::Statement *>(); 
		  }
#line 1792 "interpreter.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 269 "interpreter.y"
                  { 
			// copy up the list and add the stmt to it
			(yyval.stmts) = (yyvsp[-1].stmts);
			(yyval.stmts)->push_back((yyvsp[0].st));

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = (yyval.stmts)->begin(); 
						it != (yyval.stmts)->end(); 
						it++)
				{
					// (*it)->printAST();
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				(yyval.stmts)->clear();
			}
		}
#line 1818 "interpreter.tab.c"
    break;

  case 5: /* stmtlist: stmtlist error  */
#line 292 "interpreter.y"
      { 
			 // just copy up the stmtlist when an error occurs
			 (yyval.stmts) = (yyvsp[-1].stmts);

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       }
#line 1830 "interpreter.tab.c"
    break;

  case 6: /* switchlist: %empty  */
#line 302 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.switchl) = new std::list<lp::SwitchStmt *>(); 
		  }
#line 1839 "interpreter.tab.c"
    break;

  case 7: /* switchlist: switchlist case  */
#line 308 "interpreter.y"
                  { 
			// copy up the list and add the stmt to it
			(yyval.switchl) = (yyvsp[-1].switchl);
			(yyval.switchl)->push_back((yyvsp[0].switcht));

			
		}
#line 1851 "interpreter.tab.c"
    break;

  case 8: /* stmt: SEMICOLON  */
#line 318 "interpreter.y"
          {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 1860 "interpreter.tab.c"
    break;

  case 9: /* stmt: asgn SEMICOLON  */
#line 323 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1869 "interpreter.tab.c"
    break;

  case 10: /* stmt: print SEMICOLON  */
#line 328 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1878 "interpreter.tab.c"
    break;

  case 11: /* stmt: read SEMICOLON  */
#line 333 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1887 "interpreter.tab.c"
    break;

  case 12: /* stmt: if  */
#line 339 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1896 "interpreter.tab.c"
    break;

  case 13: /* stmt: while  */
#line 345 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1905 "interpreter.tab.c"
    break;

  case 14: /* stmt: block  */
#line 351 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1914 "interpreter.tab.c"
    break;

  case 15: /* stmt: repeat  */
#line 357 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1923 "interpreter.tab.c"
    break;

  case 16: /* stmt: for  */
#line 363 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1932 "interpreter.tab.c"
    break;

  case 17: /* stmt: switch  */
#line 369 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1941 "interpreter.tab.c"
    break;

  case 18: /* stmt: clear  */
#line 375 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	}
#line 1950 "interpreter.tab.c"
    break;

  case 19: /* stmt: place  */
#line 380 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1959 "interpreter.tab.c"
    break;

  case 20: /* block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  */
#line 388 "interpreter.y"
                {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 1968 "interpreter.tab.c"
    break;

  case 21: /* controlSymbol: %empty  */
#line 395 "interpreter.y"
                {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 1977 "interpreter.tab.c"
    break;

  case 22: /* if: IF controlSymbol cond THEN stmtlist ENDIF  */
#line 404 "interpreter.y"
    {
		// Create a new if statement node
		lp::BlockStmt* thenBlock = new lp::BlockStmt((yyvsp[-1].stmts));
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), thenBlock);

		// To control the interactive mode
		control--;
	}
#line 1990 "interpreter.tab.c"
    break;

  case 23: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist ENDIF  */
#line 415 "interpreter.y"
         {
		// Create a new if statement node
		lp::BlockStmt* thenBlock = new lp::BlockStmt((yyvsp[-3].stmts));
		lp::BlockStmt* elseBlock = new lp::BlockStmt((yyvsp[-1].stmts));
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), thenBlock, elseBlock);

		// To control the interactive mode
		control--;
	 }
#line 2004 "interpreter.tab.c"
    break;

  case 24: /* while: WHILE controlSymbol cond DO stmtlist ENDWHILE  */
#line 428 "interpreter.y"
                {
			// Create a new while statement node
			lp::BlockStmt* doBlock = new lp::BlockStmt((yyvsp[-1].stmts));
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), doBlock);

			// To control the interactive mode
			control--;
    }
#line 2017 "interpreter.tab.c"
    break;

  case 25: /* cond: LPAREN exp RPAREN  */
#line 440 "interpreter.y"
                { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 2025 "interpreter.tab.c"
    break;

  case 26: /* for: FOR VARIABLE FROM exp TO exp STEP exp DO controlSymbol stmtlist ENDFOR  */
#line 446 "interpreter.y"
                {
			// Create a new for statement node
			
			(yyval.st) = new lp::ForStmt((yyvsp[-10].string),(yyvsp[-8].expNode),(yyvsp[-6].expNode),new lp::BlockStmt((yyvsp[-1].stmts)),(yyvsp[-4].expNode));

			// To control the interactive mode
			control--;
    }
#line 2038 "interpreter.tab.c"
    break;

  case 27: /* for: FOR VARIABLE FROM exp TO exp DO controlSymbol stmtlist ENDFOR  */
#line 456 "interpreter.y"
                {
			// Create a new for statement node
			
			(yyval.st) = new lp::ForStmt((yyvsp[-8].string),(yyvsp[-6].expNode),(yyvsp[-4].expNode),new lp::BlockStmt((yyvsp[-1].stmts)),NULL);

			// To control the interactive mode
			control--;
    }
#line 2051 "interpreter.tab.c"
    break;

  case 28: /* switch: SWITCH controlSymbol LPAREN exp RPAREN switchlist ENDSWITCH  */
#line 467 "interpreter.y"
                {
			// Create a new switch statement node
			
			(yyval.st) = new lp::CaseBlockStmt((yyvsp[-3].expNode),(yyvsp[-1].switchl),NULL);

			// To control the interactive modeW
			control--;
    }
#line 2064 "interpreter.tab.c"
    break;

  case 29: /* switch: SWITCH controlSymbol LPAREN exp RPAREN switchlist DEFAULT COLON stmtlist ENDSWITCH  */
#line 477 "interpreter.y"
                {
			// Create a new switch statement node
			lp::BlockStmt* defblock = new lp::BlockStmt((yyvsp[-1].stmts)); 
			(yyval.st) = new lp::CaseBlockStmt((yyvsp[-6].expNode),(yyvsp[-4].switchl),defblock);

			// To control the interactive modeW
			control--;
    }
#line 2077 "interpreter.tab.c"
    break;

  case 30: /* case: CASE controlSymbol exp COLON stmtlist  */
#line 487 "interpreter.y"
                {
			// Create a new switch statement node
			
			(yyval.switcht) = new lp::SwitchStmt((yyvsp[-2].expNode),new lp::BlockStmt((yyvsp[0].stmts)));

			// To control the interactive mode
			control--;
    }
#line 2090 "interpreter.tab.c"
    break;

  case 31: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 498 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2099 "interpreter.tab.c"
    break;

  case 32: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 504 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2108 "interpreter.tab.c"
    break;

  case 33: /* asgn: CONSTANT ASSIGNMENT exp  */
#line 511 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].string));
		}
#line 2116 "interpreter.tab.c"
    break;

  case 34: /* asgn: CONSTANT ASSIGNMENT asgn  */
#line 516 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].string));
		}
#line 2124 "interpreter.tab.c"
    break;

  case 35: /* asgn: VARIABLE PLUS_EQUAL exp  */
#line 520 "interpreter.y"
                {
			(yyval.st) = new lp::PlusEqualNode(new lp::VariableNode((yyvsp[-2].string)),(yyvsp[0].expNode));
		}
#line 2132 "interpreter.tab.c"
    break;

  case 36: /* asgn: VARIABLE MINUS_EQUAL exp  */
#line 524 "interpreter.y"
                {
			(yyval.st) = new lp::MinusEqualNode(new lp::VariableNode((yyvsp[-2].string)),(yyvsp[0].expNode));
		}
#line 2140 "interpreter.tab.c"
    break;

  case 37: /* asgn: VARIABLE MULTIPLICATION_EQUAL exp  */
#line 528 "interpreter.y"
                {
			(yyval.st) = new lp::MultiplicationEqualNode(new lp::VariableNode((yyvsp[-2].string)),(yyvsp[0].expNode));
		}
#line 2148 "interpreter.tab.c"
    break;

  case 38: /* asgn: VARIABLE DIVISION_EQUAL exp  */
#line 532 "interpreter.y"
                {
			(yyval.st) = new lp::DivisionEqualNode(new lp::VariableNode((yyvsp[-2].string)),(yyvsp[0].expNode));
		}
#line 2156 "interpreter.tab.c"
    break;

  case 39: /* print: PRINT LPAREN exp RPAREN  */
#line 539 "interpreter.y"
                {
			// Create a new print node
			 (yyval.st) = new lp::PrintStmt((yyvsp[-1].expNode));
		}
#line 2165 "interpreter.tab.c"
    break;

  case 40: /* read: READ LPAREN VARIABLE RPAREN  */
#line 546 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
		}
#line 2174 "interpreter.tab.c"
    break;

  case 41: /* read: READ LPAREN CONSTANT RPAREN  */
#line 553 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2182 "interpreter.tab.c"
    break;

  case 42: /* read: READ_STR LPAREN VARIABLE RPAREN  */
#line 558 "interpreter.y"
                {
			(yyval.st) = new lp::ReadStrStmt((yyvsp[-1].string));
		}
#line 2190 "interpreter.tab.c"
    break;

  case 43: /* clear: CLEAR  */
#line 564 "interpreter.y"
                {
			// Create a new clear node
			(yyval.st) = new lp::ClearStmt();
			 

		}
#line 2201 "interpreter.tab.c"
    break;

  case 44: /* place: PLACE LPAREN exp COMMA exp RPAREN  */
#line 572 "interpreter.y"
                {
			// Create a new clear node
			(yyval.st) = new lp::PlaceStmt((yyvsp[-3].expNode),(yyvsp[-1].expNode));
			 

		}
#line 2212 "interpreter.tab.c"
    break;

  case 45: /* exp: NUMBER  */
#line 582 "interpreter.y"
                { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 2221 "interpreter.tab.c"
    break;

  case 46: /* exp: exp PLUS exp  */
#line 588 "interpreter.y"
                { 
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 2230 "interpreter.tab.c"
    break;

  case 47: /* exp: exp MINUS exp  */
#line 594 "interpreter.y"
        {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2239 "interpreter.tab.c"
    break;

  case 48: /* exp: exp MULTIPLICATION exp  */
#line 600 "interpreter.y"
                { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2248 "interpreter.tab.c"
    break;

  case 49: /* exp: exp DIVISION exp  */
#line 606 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2257 "interpreter.tab.c"
    break;

  case 50: /* exp: LPAREN exp RPAREN  */
#line 612 "interpreter.y"
        { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 2266 "interpreter.tab.c"
    break;

  case 51: /* exp: PLUS exp  */
#line 618 "interpreter.y"
                { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 2275 "interpreter.tab.c"
    break;

  case 52: /* exp: MINUS exp  */
#line 624 "interpreter.y"
                { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 2284 "interpreter.tab.c"
    break;

  case 53: /* exp: exp MODULO exp  */
#line 630 "interpreter.y"
                {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 2294 "interpreter.tab.c"
    break;

  case 54: /* exp: exp FLOOR_DIVISION exp  */
#line 636 "interpreter.y"
                {
			(yyval.expNode) = new lp::FloorDivisionNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2302 "interpreter.tab.c"
    break;

  case 55: /* exp: exp CONCATENATION exp  */
#line 641 "interpreter.y"
                {
			(yyval.expNode) = new lp::ConcatNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2310 "interpreter.tab.c"
    break;

  case 56: /* exp: exp POWER exp  */
#line 646 "interpreter.y"
        { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2319 "interpreter.tab.c"
    break;

  case 57: /* exp: VARIABLE  */
#line 652 "interpreter.y"
                {
		  // Create a new variable node	
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
		}
#line 2328 "interpreter.tab.c"
    break;

  case 58: /* exp: CONSTANT  */
#line 658 "interpreter.y"
                {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::ConstantNode((yyvsp[0].string));

		}
#line 2338 "interpreter.tab.c"
    break;

  case 59: /* exp: BUILTIN LPAREN listOfExp RPAREN  */
#line 665 "interpreter.y"
                {
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol((yyvsp[-3].string));

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) (yyvsp[-1].parameters)->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].string));
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 1 parameter node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].string),e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = (yyvsp[-1].parameters)->front();
							(yyvsp[-1].parameters)->pop_front();
							lp::ExpNode *e2 = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 2 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].string),e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", (yyvsp[-3].string));
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", (yyvsp[-3].string));
		}
#line 2388 "interpreter.tab.c"
    break;

  case 60: /* exp: exp GREATER_THAN exp  */
#line 712 "interpreter.y"
                {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2397 "interpreter.tab.c"
    break;

  case 61: /* exp: exp GREATER_OR_EQUAL exp  */
#line 718 "interpreter.y"
                {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2406 "interpreter.tab.c"
    break;

  case 62: /* exp: exp LESS_THAN exp  */
#line 724 "interpreter.y"
                {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2415 "interpreter.tab.c"
    break;

  case 63: /* exp: exp LESS_OR_EQUAL exp  */
#line 730 "interpreter.y"
                {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2424 "interpreter.tab.c"
    break;

  case 64: /* exp: exp EQUAL exp  */
#line 736 "interpreter.y"
                {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2433 "interpreter.tab.c"
    break;

  case 65: /* exp: exp NOT_EQUAL exp  */
#line 742 "interpreter.y"
                {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2442 "interpreter.tab.c"
    break;

  case 66: /* exp: exp AND exp  */
#line 748 "interpreter.y"
                {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2451 "interpreter.tab.c"
    break;

  case 67: /* exp: exp OR exp  */
#line 754 "interpreter.y"
                {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2460 "interpreter.tab.c"
    break;

  case 68: /* exp: NOT exp  */
#line 760 "interpreter.y"
                {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 2469 "interpreter.tab.c"
    break;

  case 69: /* exp: STRING  */
#line 766 "interpreter.y"
    {
        (yyval.expNode) = new lp::StringNode((yyvsp[0].string));
        free((yyvsp[0].string));  // liberar strdup
    }
#line 2478 "interpreter.tab.c"
    break;

  case 70: /* listOfExp: %empty  */
#line 775 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2487 "interpreter.tab.c"
    break;

  case 71: /* listOfExp: exp restOfListOfExp  */
#line 781 "interpreter.y"
                        {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2498 "interpreter.tab.c"
    break;

  case 72: /* repeat: REPEAT controlSymbol stmtlist UNTIL cond SEMICOLON  */
#line 791 "interpreter.y"
  {
	lp::BlockStmt* repeatBlock = new lp::BlockStmt((yyvsp[-3].stmts));
    (yyval.st) = new lp::RepeatStmt(repeatBlock, (yyvsp[-1].expNode));
    control--;
  }
#line 2508 "interpreter.tab.c"
    break;

  case 73: /* restOfListOfExp: %empty  */
#line 800 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2517 "interpreter.tab.c"
    break;

  case 74: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 806 "interpreter.y"
                        {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2529 "interpreter.tab.c"
    break;


#line 2533 "interpreter.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 816 "interpreter.y"




