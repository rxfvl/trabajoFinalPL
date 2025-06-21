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
    FROM = 259,                    /* FROM  */
    TO = 260,                      /* TO  */
    STEP = 261,                    /* STEP  */
    DO = 262,                      /* DO  */
    END_FOR = 263,                 /* END_FOR  */
    END_WHILE = 264,               /* END_WHILE  */
    END_IF = 265,                  /* END_IF  */
    THEN = 266,                    /* THEN  */
    READ_STRING = 267,             /* READ_STRING  */
    CASES = 268,                   /* CASES  */
    VALUE = 269,                   /* VALUE  */
    DEFAULT = 270,                 /* DEFAULT  */
    END_CASES = 271,               /* END_CASES  */
    CLEAR = 272,                   /* CLEAR  */
    PLACE = 273,                   /* PLACE  */
    UNIFORM = 274,                 /* UNIFORM  */
    PRINT = 275,                   /* PRINT  */
    READ = 276,                    /* READ  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    WHILE = 279,                   /* WHILE  */
    FOR = 280,                     /* FOR  */
    REPEAT = 281,                  /* REPEAT  */
    DOWHILE = 282,                 /* DOWHILE  */
    LETFCURLYBRACKET = 283,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 284,       /* RIGHTCURLYBRACKET  */
    ASSIGNMENT = 285,              /* ASSIGNMENT  */
    PLUSASSIGNMENT = 286,          /* PLUSASSIGNMENT  */
    MINUSASSIGNMENT = 287,         /* MINUSASSIGNMENT  */
    MULTASSIGNMENT = 288,          /* MULTASSIGNMENT  */
    DIVASSIGNMENT = 289,           /* DIVASSIGNMENT  */
    TERNARY = 290,                 /* TERNARY  */
    COMMA = 291,                   /* COMMA  */
    COLON = 292,                   /* COLON  */
    NUMBER = 293,                  /* NUMBER  */
    BOOL = 294,                    /* BOOL  */
    VARIABLE = 295,                /* VARIABLE  */
    UNDEFINED = 296,               /* UNDEFINED  */
    CONSTANT = 297,                /* CONSTANT  */
    BUILTIN = 298,                 /* BUILTIN  */
    STRING = 299,                  /* STRING  */
    OR = 300,                      /* OR  */
    AND = 301,                     /* AND  */
    GREATER_OR_EQUAL = 302,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 303,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 304,            /* GREATER_THAN  */
    LESS_THAN = 305,               /* LESS_THAN  */
    EQUAL = 306,                   /* EQUAL  */
    NOT_EQUAL = 307,               /* NOT_EQUAL  */
    NOT = 308,                     /* NOT  */
    PLUS = 309,                    /* PLUS  */
    MINUS = 310,                   /* MINUS  */
    CONCAT = 311,                  /* CONCAT  */
    MULTIPLICATION = 312,          /* MULTIPLICATION  */
    DIVISION = 313,                /* DIVISION  */
    INT_DIVISION = 314,            /* INT_DIVISION  */
    MODULO = 315,                  /* MODULO  */
    LPAREN = 316,                  /* LPAREN  */
    RPAREN = 317,                  /* RPAREN  */
    UNARY = 318,                   /* UNARY  */
    POWER = 319                    /* POWER  */
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

	lp::CaseStmt* caset;
  std::list<lp::CaseStmt*> *casesl;

#line 142 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
