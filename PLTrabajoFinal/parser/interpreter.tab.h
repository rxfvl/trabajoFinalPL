/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INTERPRETER_TAB_H_INCLUDED
# define YY_YY_INTERPRETER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    COLON = 259,                   /* COLON  */
    PRINT = 260,                   /* PRINT  */
    READ = 261,                    /* READ  */
    IF = 262,                      /* IF  */
    THEN = 263,                    /* THEN  */
    ELSE = 264,                    /* ELSE  */
    ENDIF = 265,                   /* ENDIF  */
    WHILE = 266,                   /* WHILE  */
    ENDWHILE = 267,                /* ENDWHILE  */
    CLEAR = 268,                   /* CLEAR  */
    PLACE = 269,                   /* PLACE  */
    FOR = 270,                     /* FOR  */
    FROM = 271,                    /* FROM  */
    TO = 272,                      /* TO  */
    STEP = 273,                    /* STEP  */
    ENDFOR = 274,                  /* ENDFOR  */
    SWITCH = 275,                  /* SWITCH  */
    CASE = 276,                    /* CASE  */
    DEFAULT = 277,                 /* DEFAULT  */
    ENDSWITCH = 278,               /* ENDSWITCH  */
    READ_STR = 279,                /* READ_STR  */
    LETFCURLYBRACKET = 280,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 281,       /* RIGHTCURLYBRACKET  */
    REPEAT = 282,                  /* REPEAT  */
    UNTIL = 283,                   /* UNTIL  */
    DO = 284,                      /* DO  */
    STRING = 285,                  /* STRING  */
    ASSIGNMENT = 286,              /* ASSIGNMENT  */
    COMMA = 287,                   /* COMMA  */
    NUMBER = 288,                  /* NUMBER  */
    BOOL = 289,                    /* BOOL  */
    VARIABLE = 290,                /* VARIABLE  */
    UNDEFINED = 291,               /* UNDEFINED  */
    CONSTANT = 292,                /* CONSTANT  */
    BUILTIN = 293,                 /* BUILTIN  */
    OR = 294,                      /* OR  */
    AND = 295,                     /* AND  */
    GREATER_OR_EQUAL = 296,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 297,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 298,            /* GREATER_THAN  */
    LESS_THAN = 299,               /* LESS_THAN  */
    EQUAL = 300,                   /* EQUAL  */
    NOT_EQUAL = 301,               /* NOT_EQUAL  */
    NOT = 302,                     /* NOT  */
    PLUS = 303,                    /* PLUS  */
    MINUS = 304,                   /* MINUS  */
    MULTIPLICATION = 305,          /* MULTIPLICATION  */
    DIVISION = 306,                /* DIVISION  */
    MODULO = 307,                  /* MODULO  */
    FLOOR_DIVISION = 308,          /* FLOOR_DIVISION  */
    LPAREN = 309,                  /* LPAREN  */
    RPAREN = 310,                  /* RPAREN  */
    CONCATENATION = 311,           /* CONCATENATION  */
    UNARY = 312,                   /* UNARY  */
    POWER = 313                    /* POWER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 141 "interpreter.y"

  double number;
  char * string; 				 /* NEW in example 7 */
  bool logic;						 /* NEW in example 15 */
  lp::ExpNode *expNode;  			 /* NEW in example 16 */
  std::list<lp::ExpNode *>  *parameters;    // New in example 16; NOTE: #include<list> must be in interpreter.l, init.cpp, interpreter.cpp
  std::list<lp::Statement *> *stmts; /* NEW in example 16 */
  lp::Statement *st;				 /* NEW in example 16 */
  lp::AST *prog;					 /* NEW in example 16 */

  lp::SwitchStmt* switcht;
  std::list<lp::SwitchStmt*> *switchl;

#line 136 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
