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
    PRINT = 259,                   /* PRINT  */
    READ = 260,                    /* READ  */
    IF = 261,                      /* IF  */
    THEN = 262,                    /* THEN  */
    ELSE = 263,                    /* ELSE  */
    ENDIF = 264,                   /* ENDIF  */
    WHILE = 265,                   /* WHILE  */
    ENDWHILE = 266,                /* ENDWHILE  */
    FOR = 267,                     /* FOR  */
    FROM = 268,                    /* FROM  */
    TO = 269,                      /* TO  */
    STEP = 270,                    /* STEP  */
    ENDFOR = 271,                  /* ENDFOR  */
    SWITCH = 272,                  /* SWITCH  */
    CASE = 273,                    /* CASE  */
    DEFAULT = 274,                 /* DEFAULT  */
    ENDSWITCH = 275,               /* ENDSWITCH  */
    READ_STR = 276,                /* READ_STR  */
    LETFCURLYBRACKET = 277,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 278,       /* RIGHTCURLYBRACKET  */
    REPEAT = 279,                  /* REPEAT  */
    UNTIL = 280,                   /* UNTIL  */
    DO = 281,                      /* DO  */
    STRING = 282,                  /* STRING  */
    ASSIGNMENT = 283,              /* ASSIGNMENT  */
    COMMA = 284,                   /* COMMA  */
    NUMBER = 285,                  /* NUMBER  */
    BOOL = 286,                    /* BOOL  */
    VARIABLE = 287,                /* VARIABLE  */
    UNDEFINED = 288,               /* UNDEFINED  */
    CONSTANT = 289,                /* CONSTANT  */
    BUILTIN = 290,                 /* BUILTIN  */
    OR = 291,                      /* OR  */
    AND = 292,                     /* AND  */
    GREATER_OR_EQUAL = 293,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 294,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 295,            /* GREATER_THAN  */
    LESS_THAN = 296,               /* LESS_THAN  */
    EQUAL = 297,                   /* EQUAL  */
    NOT_EQUAL = 298,               /* NOT_EQUAL  */
    NOT = 299,                     /* NOT  */
    PLUS = 300,                    /* PLUS  */
    MINUS = 301,                   /* MINUS  */
    MULTIPLICATION = 302,          /* MULTIPLICATION  */
    DIVISION = 303,                /* DIVISION  */
    MODULO = 304,                  /* MODULO  */
    FLOOR_DIVISION = 305,          /* FLOOR_DIVISION  */
    LPAREN = 306,                  /* LPAREN  */
    RPAREN = 307,                  /* RPAREN  */
    CONCATENATION = 308,           /* CONCATENATION  */
    UNARY = 309,                   /* UNARY  */
    POWER = 310                    /* POWER  */
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

#line 133 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
