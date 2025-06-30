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
  YYSYMBOL_UNARY = 57,                     /* UNARY  */
  YYSYMBOL_POWER = 58,                     /* POWER  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_stmtlist = 61,                  /* stmtlist  */
  YYSYMBOL_switchlist = 62,                /* switchlist  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_block = 64,                     /* block  */
  YYSYMBOL_controlSymbol = 65,             /* controlSymbol  */
  YYSYMBOL_if = 66,                        /* if  */
  YYSYMBOL_while = 67,                     /* while  */
  YYSYMBOL_cond = 68,                      /* cond  */
  YYSYMBOL_for = 69,                       /* for  */
  YYSYMBOL_switch = 70,                    /* switch  */
  YYSYMBOL_case = 71,                      /* case  */
  YYSYMBOL_asgn = 72,                      /* asgn  */
  YYSYMBOL_print = 73,                     /* print  */
  YYSYMBOL_read = 74,                      /* read  */
  YYSYMBOL_clear = 75,                     /* clear  */
  YYSYMBOL_place = 76,                     /* place  */
  YYSYMBOL_exp = 77,                       /* exp  */
  YYSYMBOL_listOfExp = 78,                 /* listOfExp  */
  YYSYMBOL_repeat = 79,                    /* repeat  */
  YYSYMBOL_restOfListOfExp = 80            /* restOfListOfExp  */
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
#define YYLAST   724

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   247,   247,   261,   266,   289,   300,   305,   315,   320,
     325,   330,   336,   342,   348,   354,   360,   366,   372,   377,
     385,   393,   401,   412,   425,   437,   443,   453,   464,   474,
     484,   495,   501,   508,   513,   519,   526,   533,   538,   544,
     552,   562,   568,   574,   580,   586,   592,   598,   604,   610,
     616,   621,   626,   632,   638,   645,   692,   698,   704,   710,
     716,   722,   728,   734,   740,   746,   756,   761,   771,   781,
     786
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
  "LPAREN", "RPAREN", "CONCATENATION", "UNARY", "POWER", "$accept",
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

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -50,    10,   197,   -50,   -50,   -50,   -42,   -40,   -50,   -50,
     -50,   -26,    -6,   -50,   -24,   -50,   -50,     0,     6,   -50,
     -50,   -50,   -50,   -50,   -50,    35,    36,    38,   -50,   -50,
     -50,   -22,   -32,   -12,   -12,   -22,    27,    -1,    16,   280,
     307,    79,    79,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
       2,   -22,   -22,   -22,   -22,   511,     3,    22,   -22,    49,
      50,   469,   -22,   -22,    23,   -50,   -50,     0,     6,   -50,
     611,   -50,   611,   -22,   118,    42,    42,   531,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -50,   -22,   -22,   -50,   -50,   551,   -50,   -50,
     -22,   107,   571,   -50,   -12,   491,    25,   -50,   630,   648,
     666,   666,   666,   666,   666,   666,    -4,    -4,   -49,   -49,
     -49,   -49,    42,    42,   -50,   255,   340,   591,   -22,   -50,
      78,   -22,   -50,   -50,   -50,   -50,   -50,   -50,   143,    -3,
     -50,   491,   373,   -22,   -50,   -50,    89,   -50,   -50,   -50,
     -50,   447,   398,   -22,   -50,   -50,   -50,    46,   423,   448,
     -50,   -50,   -50,   222
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     5,     8,     0,     0,    21,    21,
      39,     0,     0,    21,     0,     3,     3,     0,     0,     4,
      14,    12,    13,    16,    17,     0,     0,     0,    18,    19,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    65,    41,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    21,    53,    54,    32,
      31,    34,    33,    66,    64,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,    36,    37,     0,     3,     3,
       0,     0,     0,    38,     0,    69,     0,    46,    63,    62,
      57,    59,    56,    58,    60,    61,    42,    43,    44,    45,
      49,    50,    51,    52,    25,     0,     0,     0,     0,     6,
       0,     0,    67,    55,     3,    22,    24,    40,     0,     0,
      68,    69,     0,     0,     3,    21,     0,    28,     7,    70,
      23,     0,     0,     0,     3,     3,    27,     0,     0,     0,
       3,    29,    26,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -15,   -50,   -50,   -50,    -7,   -50,   -50,   -30,
     -50,   -50,   -50,   -20,   -50,   -50,   -50,   -50,   -18,   -50,
     -50,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   139,    19,    20,    33,    21,    22,    59,
      23,    24,   148,    25,    26,    27,    28,    29,    55,   106,
      30,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    40,    34,    56,    60,    57,    37,    93,    46,    94,
       3,    47,    31,    48,    32,    49,    50,    61,   145,   146,
     147,    69,    71,    70,    72,    51,    52,    53,    35,    36,
      38,    41,    54,    74,    75,    76,    77,    42,    43,    44,
      97,    45,    58,    62,   101,   102,    88,    89,    90,    91,
     160,    64,    93,    63,    94,   105,    73,    98,    95,   104,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   130,   122,   123,    96,   103,    99,
     133,   140,   127,   125,   126,    78,    79,    80,    81,    82,
      83,    84,    85,   154,    86,    87,    88,    89,    90,    91,
      94,     0,    93,   149,    94,     0,     0,     0,     0,    46,
     138,     0,    47,   141,    67,     0,    68,    50,     0,   142,
       0,     0,     0,     0,   128,   151,    51,    52,    53,   152,
       0,     0,     0,    54,     0,   157,     0,     0,   153,   158,
     159,     0,     0,     0,     0,   163,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    86,    87,    88,    89,    90,
      91,   143,     0,    93,     0,    94,    86,    87,    88,    89,
      90,    91,   144,     0,    93,     0,    94,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    -2,     4,    93,
       5,    94,     6,     7,     8,     0,     0,     0,     9,     0,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,    14,    15,     4,    16,     5,     0,     6,     7,     8,
       0,     0,    17,     9,    18,    10,    11,    12,     0,     0,
       0,     0,    13,   -30,   -30,   -30,    14,    15,     0,    16,
       0,     0,     0,     0,     0,     0,     4,    17,     5,    18,
       6,     7,     8,     0,   134,   135,     9,     0,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,    14,
      15,     4,    16,     5,     0,     6,     7,     8,     0,     0,
      17,     9,    18,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,    15,    65,    16,     4,     0,
       5,     0,     6,     7,     8,    17,     0,    18,     9,     0,
      10,    11,    12,     0,     0,     0,     0,    13,     0,     0,
       0,    14,    15,     0,    16,    66,     0,     0,     0,     0,
       0,     4,    17,     5,    18,     6,     7,     8,     0,     0,
       0,     9,   136,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     4,    17,     5,    18,     6,     7,
       8,     0,     0,   150,     9,     0,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,    14,    15,     4,
      16,     5,     0,     6,     7,     8,     0,     0,    17,     9,
      18,    10,    11,    12,     0,     0,     0,   156,    13,     0,
       0,     0,    14,    15,     4,    16,     5,     0,     6,     7,
       8,     0,     0,    17,     9,    18,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,   161,    14,    15,     4,
      16,     5,     0,     6,     7,     8,     0,     0,    17,     9,
      18,    10,    11,    12,     0,     0,     0,   162,    13,     0,
       0,     0,    14,    15,     0,    16,   155,     0,     0,     0,
       0,     0,     0,    17,     0,    18,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    86,    87,    88,    89,    90,
      91,   100,     0,    93,     0,    94,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    91,   131,     0,    93,     0,    94,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,     0,    93,     0,    94,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,    92,    93,     0,    94,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,   107,    93,     0,    94,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,   124,    93,     0,    94,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,   129,    93,     0,    94,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,   137,    93,     0,    94,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,     0,     0,    93,     0,    94,
      79,    80,    81,    82,    83,    84,    85,     0,    86,    87,
      88,    89,    90,    91,     0,     0,    93,     0,    94,    80,
      81,    82,    83,    84,    85,     0,    86,    87,    88,    89,
      90,    91,     0,     0,    93,     0,    94,   -31,   -31,   -31,
     -31,   -31,   -31,     0,    86,    87,    88,    89,    90,    91,
       0,     0,    93,     0,    94
};

static const yytype_int16 yycheck[] =
{
      15,    16,     9,    35,    34,    37,    13,    56,    30,    58,
       0,    33,    54,    35,    54,    37,    38,    35,    21,    22,
      23,    41,    42,    41,    42,    47,    48,    49,    54,    35,
      54,    31,    54,    51,    52,    53,    54,    31,     3,     3,
      58,     3,    54,    16,    62,    63,    50,    51,    52,    53,
       4,    35,    56,    54,    58,    73,    54,     8,    55,    66,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   104,    93,    94,    55,    55,    29,
      55,     3,   100,    98,    99,    39,    40,    41,    42,    43,
      44,    45,    46,     4,    48,    49,    50,    51,    52,    53,
      58,    -1,    56,   141,    58,    -1,    -1,    -1,    -1,    30,
     128,    -1,    33,   131,    35,    -1,    37,    38,    -1,   134,
      -1,    -1,    -1,    -1,    17,   143,    47,    48,    49,   144,
      -1,    -1,    -1,    54,    -1,   153,    -1,    -1,   145,   154,
     155,    -1,    -1,    -1,    -1,   160,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    18,    -1,    56,    -1,    58,    48,    49,    50,    51,
      52,    53,    29,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,     0,     1,    56,
       3,    58,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,     1,    27,     3,    -1,     5,     6,     7,
      -1,    -1,    35,    11,    37,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    35,     3,    37,
       5,     6,     7,    -1,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,     1,    27,     3,    -1,     5,     6,     7,    -1,    -1,
      35,    11,    37,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    26,    27,     1,    -1,
       3,    -1,     5,     6,     7,    35,    -1,    37,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,     1,    35,     3,    37,     5,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    35,     3,    37,     5,     6,
       7,    -1,    -1,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,     1,
      27,     3,    -1,     5,     6,     7,    -1,    -1,    35,    11,
      37,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    24,    25,     1,    27,     3,    -1,     5,     6,
       7,    -1,    -1,    35,    11,    37,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    23,    24,    25,     1,
      27,     3,    -1,     5,     6,     7,    -1,    -1,    35,    11,
      37,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    24,    25,    -1,    27,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    32,    -1,    56,    -1,    58,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    32,    -1,    56,    -1,    58,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    58,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    -1,    58,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    58,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,    61,     0,     1,     3,     5,     6,     7,    11,
      13,    14,    15,    20,    24,    25,    27,    35,    37,    63,
      64,    66,    67,    69,    70,    72,    73,    74,    75,    76,
      79,    54,    54,    65,    65,    54,    35,    65,    54,    61,
      61,    31,    31,     3,     3,     3,    30,    33,    35,    37,
      38,    47,    48,    49,    54,    77,    35,    37,    54,    68,
      68,    77,    16,    54,    35,    26,    28,    35,    37,    72,
      77,    72,    77,    54,    77,    77,    77,    77,    39,    40,
      41,    42,    43,    44,    45,    46,    48,    49,    50,    51,
      52,    53,    55,    56,    58,    55,    55,    77,     8,    29,
      32,    77,    77,    55,    65,    77,    78,    55,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    55,    61,    61,    77,    17,    55,
      68,    32,    80,    55,     9,    10,    12,    55,    77,    62,
       3,    77,    61,    18,    29,    21,    22,    23,    71,    80,
      10,    77,    61,    65,     4,    29,    19,    77,    61,    61,
       4,    23,    19,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    66,    66,    67,    68,    69,    69,    70,    70,
      71,    72,    72,    72,    72,    73,    74,    74,    74,    75,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    79,    80,
      80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     0,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     6,     8,     6,     3,    11,     9,     7,    10,
       5,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       6,     1,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     0,     2,     6,     0,
       3
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
#line 248 "interpreter.y"
                  { 
		    // Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog); 

			// End of parsing
			//	return 1;
		  }
#line 1757 "interpreter.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 261 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.stmts) = new std::list<lp::Statement *>(); 
		  }
#line 1766 "interpreter.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 267 "interpreter.y"
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
					(*it)->printAST();
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				(yyval.stmts)->clear();
			}
		}
#line 1792 "interpreter.tab.c"
    break;

  case 5: /* stmtlist: stmtlist error  */
#line 290 "interpreter.y"
      { 
			 // just copy up the stmtlist when an error occurs
			 (yyval.stmts) = (yyvsp[-1].stmts);

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       }
#line 1804 "interpreter.tab.c"
    break;

  case 6: /* switchlist: %empty  */
#line 300 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.switchl) = new std::list<lp::SwitchStmt *>(); 
		  }
#line 1813 "interpreter.tab.c"
    break;

  case 7: /* switchlist: switchlist case  */
#line 306 "interpreter.y"
                  { 
			// copy up the list and add the stmt to it
			(yyval.switchl) = (yyvsp[-1].switchl);
			(yyval.switchl)->push_back((yyvsp[0].switcht));

			
		}
#line 1825 "interpreter.tab.c"
    break;

  case 8: /* stmt: SEMICOLON  */
#line 316 "interpreter.y"
          {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 1834 "interpreter.tab.c"
    break;

  case 9: /* stmt: asgn SEMICOLON  */
#line 321 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1843 "interpreter.tab.c"
    break;

  case 10: /* stmt: print SEMICOLON  */
#line 326 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1852 "interpreter.tab.c"
    break;

  case 11: /* stmt: read SEMICOLON  */
#line 331 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1861 "interpreter.tab.c"
    break;

  case 12: /* stmt: if  */
#line 337 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1870 "interpreter.tab.c"
    break;

  case 13: /* stmt: while  */
#line 343 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1879 "interpreter.tab.c"
    break;

  case 14: /* stmt: block  */
#line 349 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1888 "interpreter.tab.c"
    break;

  case 15: /* stmt: repeat  */
#line 355 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1897 "interpreter.tab.c"
    break;

  case 16: /* stmt: for  */
#line 361 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1906 "interpreter.tab.c"
    break;

  case 17: /* stmt: switch  */
#line 367 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1915 "interpreter.tab.c"
    break;

  case 18: /* stmt: clear  */
#line 373 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	}
#line 1924 "interpreter.tab.c"
    break;

  case 19: /* stmt: place  */
#line 378 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1933 "interpreter.tab.c"
    break;

  case 20: /* block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  */
#line 386 "interpreter.y"
                {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 1942 "interpreter.tab.c"
    break;

  case 21: /* controlSymbol: %empty  */
#line 393 "interpreter.y"
                {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 1951 "interpreter.tab.c"
    break;

  case 22: /* if: IF controlSymbol cond THEN stmtlist ENDIF  */
#line 402 "interpreter.y"
    {
		// Create a new if statement node
		lp::BlockStmt* thenBlock = new lp::BlockStmt((yyvsp[-1].stmts));
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), thenBlock);

		// To control the interactive mode
		control--;
	}
#line 1964 "interpreter.tab.c"
    break;

  case 23: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist ENDIF  */
#line 413 "interpreter.y"
         {
		// Create a new if statement node
		lp::BlockStmt* thenBlock = new lp::BlockStmt((yyvsp[-3].stmts));
		lp::BlockStmt* elseBlock = new lp::BlockStmt((yyvsp[-1].stmts));
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), thenBlock, elseBlock);

		// To control the interactive mode
		control--;
	 }
#line 1978 "interpreter.tab.c"
    break;

  case 24: /* while: WHILE controlSymbol cond DO stmtlist ENDWHILE  */
#line 426 "interpreter.y"
                {
			// Create a new while statement node
			lp::BlockStmt* doBlock = new lp::BlockStmt((yyvsp[-1].stmts));
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), doBlock);

			// To control the interactive mode
			control--;
    }
#line 1991 "interpreter.tab.c"
    break;

  case 25: /* cond: LPAREN exp RPAREN  */
#line 438 "interpreter.y"
                { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 1999 "interpreter.tab.c"
    break;

  case 26: /* for: FOR VARIABLE FROM exp TO exp STEP exp DO stmtlist ENDFOR  */
#line 444 "interpreter.y"
                {
			// Create a new for statement node
			
			(yyval.st) = new lp::ForStmt((yyvsp[-9].string),(yyvsp[-7].expNode),(yyvsp[-5].expNode),new lp::BlockStmt((yyvsp[-1].stmts)),(yyvsp[-3].expNode));

			// To control the interactive mode
			control--;
    }
#line 2012 "interpreter.tab.c"
    break;

  case 27: /* for: FOR VARIABLE FROM exp TO exp DO stmtlist ENDFOR  */
#line 454 "interpreter.y"
                {
			// Create a new for statement node
			
			(yyval.st) = new lp::ForStmt((yyvsp[-7].string),(yyvsp[-5].expNode),(yyvsp[-3].expNode),new lp::BlockStmt((yyvsp[-1].stmts)),NULL);

			// To control the interactive mode
			control--;
    }
#line 2025 "interpreter.tab.c"
    break;

  case 28: /* switch: SWITCH controlSymbol LPAREN exp RPAREN switchlist ENDSWITCH  */
#line 465 "interpreter.y"
                {
			// Create a new switch statement node
			
			(yyval.st) = new lp::CaseBlockStmt((yyvsp[-3].expNode),(yyvsp[-1].switchl),NULL);

			// To control the interactive modeW
			control--;
    }
#line 2038 "interpreter.tab.c"
    break;

  case 29: /* switch: SWITCH controlSymbol LPAREN exp RPAREN switchlist DEFAULT COLON stmtlist ENDSWITCH  */
#line 475 "interpreter.y"
                {
			// Create a new switch statement node
			lp::BlockStmt* defblock = new lp::BlockStmt((yyvsp[-1].stmts)); 
			(yyval.st) = new lp::CaseBlockStmt((yyvsp[-6].expNode),(yyvsp[-4].switchl),defblock);

			// To control the interactive modeW
			control--;
    }
#line 2051 "interpreter.tab.c"
    break;

  case 30: /* case: CASE controlSymbol exp COLON stmtlist  */
#line 485 "interpreter.y"
                {
			// Create a new switch statement node
			
			(yyval.switcht) = new lp::SwitchStmt((yyvsp[-2].expNode),new lp::BlockStmt((yyvsp[0].stmts)));

			// To control the interactive mode
			control--;
    }
#line 2064 "interpreter.tab.c"
    break;

  case 31: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 496 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2073 "interpreter.tab.c"
    break;

  case 32: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 502 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2082 "interpreter.tab.c"
    break;

  case 33: /* asgn: CONSTANT ASSIGNMENT exp  */
#line 509 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].string));
		}
#line 2090 "interpreter.tab.c"
    break;

  case 34: /* asgn: CONSTANT ASSIGNMENT asgn  */
#line 514 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].string));
		}
#line 2098 "interpreter.tab.c"
    break;

  case 35: /* print: PRINT LPAREN exp RPAREN  */
#line 520 "interpreter.y"
                {
			// Create a new print node
			 (yyval.st) = new lp::PrintStmt((yyvsp[-1].expNode));
		}
#line 2107 "interpreter.tab.c"
    break;

  case 36: /* read: READ LPAREN VARIABLE RPAREN  */
#line 527 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
		}
#line 2116 "interpreter.tab.c"
    break;

  case 37: /* read: READ LPAREN CONSTANT RPAREN  */
#line 534 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2124 "interpreter.tab.c"
    break;

  case 38: /* read: READ_STR LPAREN VARIABLE RPAREN  */
#line 539 "interpreter.y"
                {
			(yyval.st) = new lp::ReadStrStmt((yyvsp[-1].string));
		}
#line 2132 "interpreter.tab.c"
    break;

  case 39: /* clear: CLEAR  */
#line 545 "interpreter.y"
                {
			// Create a new clear node
			(yyval.st) = new lp::ClearStmt();
			 

		}
#line 2143 "interpreter.tab.c"
    break;

  case 40: /* place: PLACE LPAREN exp COMMA exp RPAREN  */
#line 553 "interpreter.y"
                {
			// Create a new clear node
			(yyval.st) = new lp::PlaceStmt((yyvsp[-3].expNode),(yyvsp[-1].expNode));
			 

		}
#line 2154 "interpreter.tab.c"
    break;

  case 41: /* exp: NUMBER  */
#line 563 "interpreter.y"
                { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 2163 "interpreter.tab.c"
    break;

  case 42: /* exp: exp PLUS exp  */
#line 569 "interpreter.y"
                { 
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 2172 "interpreter.tab.c"
    break;

  case 43: /* exp: exp MINUS exp  */
#line 575 "interpreter.y"
        {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2181 "interpreter.tab.c"
    break;

  case 44: /* exp: exp MULTIPLICATION exp  */
#line 581 "interpreter.y"
                { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2190 "interpreter.tab.c"
    break;

  case 45: /* exp: exp DIVISION exp  */
#line 587 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2199 "interpreter.tab.c"
    break;

  case 46: /* exp: LPAREN exp RPAREN  */
#line 593 "interpreter.y"
        { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 2208 "interpreter.tab.c"
    break;

  case 47: /* exp: PLUS exp  */
#line 599 "interpreter.y"
                { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 2217 "interpreter.tab.c"
    break;

  case 48: /* exp: MINUS exp  */
#line 605 "interpreter.y"
                { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 2226 "interpreter.tab.c"
    break;

  case 49: /* exp: exp MODULO exp  */
#line 611 "interpreter.y"
                {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 2236 "interpreter.tab.c"
    break;

  case 50: /* exp: exp FLOOR_DIVISION exp  */
#line 617 "interpreter.y"
                {
			(yyval.expNode) = new lp::FloorDivisionNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2244 "interpreter.tab.c"
    break;

  case 51: /* exp: exp CONCATENATION exp  */
#line 622 "interpreter.y"
                {
			(yyval.expNode) = new lp::ConcatNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2252 "interpreter.tab.c"
    break;

  case 52: /* exp: exp POWER exp  */
#line 627 "interpreter.y"
        { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2261 "interpreter.tab.c"
    break;

  case 53: /* exp: VARIABLE  */
#line 633 "interpreter.y"
                {
		  // Create a new variable node	
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
		}
#line 2270 "interpreter.tab.c"
    break;

  case 54: /* exp: CONSTANT  */
#line 639 "interpreter.y"
                {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::ConstantNode((yyvsp[0].string));

		}
#line 2280 "interpreter.tab.c"
    break;

  case 55: /* exp: BUILTIN LPAREN listOfExp RPAREN  */
#line 646 "interpreter.y"
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
#line 2330 "interpreter.tab.c"
    break;

  case 56: /* exp: exp GREATER_THAN exp  */
#line 693 "interpreter.y"
                {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2339 "interpreter.tab.c"
    break;

  case 57: /* exp: exp GREATER_OR_EQUAL exp  */
#line 699 "interpreter.y"
                {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2348 "interpreter.tab.c"
    break;

  case 58: /* exp: exp LESS_THAN exp  */
#line 705 "interpreter.y"
                {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2357 "interpreter.tab.c"
    break;

  case 59: /* exp: exp LESS_OR_EQUAL exp  */
#line 711 "interpreter.y"
                {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2366 "interpreter.tab.c"
    break;

  case 60: /* exp: exp EQUAL exp  */
#line 717 "interpreter.y"
                {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2375 "interpreter.tab.c"
    break;

  case 61: /* exp: exp NOT_EQUAL exp  */
#line 723 "interpreter.y"
                {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2384 "interpreter.tab.c"
    break;

  case 62: /* exp: exp AND exp  */
#line 729 "interpreter.y"
                {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2393 "interpreter.tab.c"
    break;

  case 63: /* exp: exp OR exp  */
#line 735 "interpreter.y"
                {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2402 "interpreter.tab.c"
    break;

  case 64: /* exp: NOT exp  */
#line 741 "interpreter.y"
                {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 2411 "interpreter.tab.c"
    break;

  case 65: /* exp: STRING  */
#line 747 "interpreter.y"
    {
        (yyval.expNode) = new lp::StringNode((yyvsp[0].string));
        free((yyvsp[0].string));  // liberar strdup
    }
#line 2420 "interpreter.tab.c"
    break;

  case 66: /* listOfExp: %empty  */
#line 756 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2429 "interpreter.tab.c"
    break;

  case 67: /* listOfExp: exp restOfListOfExp  */
#line 762 "interpreter.y"
                        {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2440 "interpreter.tab.c"
    break;

  case 68: /* repeat: REPEAT stmtlist UNTIL controlSymbol cond SEMICOLON  */
#line 772 "interpreter.y"
  {
	lp::BlockStmt* repeatBlock = new lp::BlockStmt((yyvsp[-4].stmts));
    (yyval.st) = new lp::RepeatStmt(repeatBlock, (yyvsp[-1].expNode));
    control--;
  }
#line 2450 "interpreter.tab.c"
    break;

  case 69: /* restOfListOfExp: %empty  */
#line 781 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2459 "interpreter.tab.c"
    break;

  case 70: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 787 "interpreter.y"
                        {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2471 "interpreter.tab.c"
    break;


#line 2475 "interpreter.tab.c"

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

#line 797 "interpreter.y"




