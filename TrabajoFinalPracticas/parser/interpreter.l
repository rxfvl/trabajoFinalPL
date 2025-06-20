/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/
%{
#include <iostream>

/*********************/
/* NEW in example 4 */
/* atof */
#include <stdlib.h>
/*********************/

/* Macros for the screen */
#include "../includes/macros.hpp"

/*********************/
/* 
  NEW in example 16 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "../ast/ast.hpp"
/*********************/

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

/********************/
/* NEW in example 3 */
#include "../error/error.hpp"
/********************/


/*********************************************/
/* NEW in example 7 */
/* Table of symbols */
#include "../table/table.hpp"

#include "../table/numericVariable.hpp"

extern lp::Table table; //!< External Table of Symbols
/*********************************************/

extern int lineNumber; //!< External line counter

/* uso de strdup */
#include <string.h>


%}


/*! \name REGULAR DEFINITIONS  */

DIGIT  [0-9] 

LETTER [a-zA-Z]

NUMBER1 {DIGIT}+\.?

NUMBER2 {DIGIT}*\.{DIGIT}+

NUMBER3 ({DIGIT}+(e|E)(\+|\-){DIGIT}+)

BAD_NUMBER1 {DIGIT}{LETTER}+{DIGIT}*\..*
BAD_NUMBER2 {LETTER}+{DIGIT}+\..*
BAD_NUMBER3 {LETTER}+{DIGIT}+{LETTER}+\..*
BAD_NUMBER4 \..*

BAD_NUMBER {BAD_NUMBER1}|{BAD_NUMBER2}|{BAD_NUMBER3}|{BAD_NUMBER4}
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|(_{LETTER}|{DIGIT}))*

BAD_IDENTIFIER  ^_.*
BAD_IDENTIFIER2  .*__.*

BAD_SYMBOL .*($|&|@).*

CADENA \'((\\')|[^'])*\'

COMENTARIO !!.*
/* NEW in example 3 */
/* STATE  */
%x ERROR Q1

/*! \name REGULAR EXPRESSIONS  */
%%
{COMENTARIO} {lineNumber++;}

"<<" {
	yymore();

	BEGIN(Q1);
}
<Q1>"\n" {
	yymore();
	lineNumber++;
}
<Q1>. {
	yymore();
}
<Q1>">>" {
	yymore();
	lineNumber++;
	BEGIN(INITIAL);

}
[ \t] 	{ ; }    /* skip white space and tabular */

\n      { 
			/* Line counter */
           	lineNumber++; 
	
			/* MODIFIED in example 3 */
			/* COMMENTED in example 5 */
        	/* return NEWLINE; */
        }

";"		{
			/* NEW in example 5 */
			return SEMICOLON;
		}


","		{
			/* NEW in example 14 */
			return COMMA;
		}
{BAD_NUMBER} {
	std::cout<<"ERROR, número incorrecto ->"<<yytext<<std::endl;
	return -1;

}

{BAD_SYMBOL} {
	std::cout<<"ERROR, símbolo incorrecto ->"<<yytext<<std::endl;
	return -1;

}
{NUMBER1}|{NUMBER2}|{NUMBER3}  {
					  /* MODIFIED in example 4 */
					  /* Conversion of type and sending of the numerical value to the parser */
					   yylval.number = atof(yytext); 

                       return NUMBER; 
                      }

{CADENA}  {
    /* MODIFICADO en el ejemplo */
    /* Conversión del tipo y envío del valor numérico al analizador */

    // Reserva memoria para el resultado
    char* result = (char*)malloc(strlen(yytext) * sizeof(char));

    int j = 0;
    bool isEscaped = false;

    for (int i = 0; yytext[i] != '\0'; i++) {
		
        if (yytext[i] == '\\' && !isEscaped) {
            // Si encuentra una barra invertida, marca que el siguiente carácter está escapado
            isEscaped = true;
        } else if (yytext[i] == '\'' && !isEscaped) {
            // Si encuentra una comilla simple no escapada, copiarla al resultado
            continue;
        } 
		else if (isEscaped && (yytext[i]=='n' || yytext[i]=='t')){
			if (yytext[i] == 'n') {
				result[j++] = '\n';
			} else {
				result[j++] = '\t';
			}
			
            isEscaped = false;
		}
		else {
            // En cualquier otro caso, copiar el carácter al resultado
            result[j++] = yytext[i];
            isEscaped = false;
        }
    }

    // Termina el resultado con un carácter nulo
    result[j] = '\0';
    yylval.string = result;
    return STRING;
}

{BAD_IDENTIFIER}|{BAD_IDENTIFIER2} {
	std::cout<<"ERROR, identificador incorrecto ->"<<yytext<<std::endl;
	return -1;

}
{IDENTIFIER}   		 {
						 /* NEW in example 7 */
						 std::string identifier(yytext);
						 for (int i = 0; i < identifier.length(); i++) {
								
								identifier[i] = tolower(identifier[i]);
							}

						/* 
                          strdup() function returns a pointer to a new string 
                          which  is a duplicate of the string yytext
                        */
						  yylval.string =  strdup(identifier.c_str());

						/* If the identifier is not in the table of symbols then it is inserted */	
						 if (table.lookupSymbol(identifier) == false)
							{
								/* 
								 The identifier is inserted into the symbol table 
								 as undefined Variable with value 0.0
								*/
								lp::NumericVariable *n = new lp::NumericVariable(identifier,VARIABLE,UNDEFINED,0.0);

								/* A pointer to the new NumericVariable is inserted into the table of symbols */
								table.installSymbol(n);

								return VARIABLE;
							}

						/* MODIFIED in example 11 */
						/* 
							If the identifier is in the table of symbols then its token is returned 
								The identifier can be a variable or a numeric constant
						*/
						else 
							{
								lp::Symbol	*s = table.getSymbol(identifier);

/*
								std::cout << "lex: "<< s->getName() 
										  << "token " << s->getToken()
  										  << std::endl; 
*/

								/*  If the identifier is in the table then its token is returned  */
								return s->getToken();
							}
                     }
					 
"?"		{ return TERNARY;  } 
"-"		{ return MINUS;  } 			/* NEW in example 3 */
"+"		{ return PLUS;   } 			/* NEW in example 3 */

"//"     { return INT_DIVISION; }
"/"     { return DIVISION; } 		/* NEW in example 3 */

"("     { return LPAREN; } 			/* NEW in example 3 */
")"	    { return RPAREN; } 			/* NEW in example 3 */
"||"  { return CONCAT;}


"%"     { return MODULO; }			/* NEW in example 5 */

"**"	    { return POWER; }			/* NEW in example 5 */
"*"	    { return MULTIPLICATION; } 	/* NEW in example 3 */
":*=" 	{ return MULTASSIGNMENT; }
":/=" 	{ return DIVASSIGNMENT; }
":+=" 	{ return PLUSASSIGNMENT; }
":-=" 	{ return MINUSASSIGNMENT; }
":=" 	{ return ASSIGNMENT; }		/* NEW in example 7 */


"="	{ return EQUAL; }			/* NEW in example 15 */

"<>"	{ return NOT_EQUAL; }		/* NEW in example 15 */

">="	{ return GREATER_OR_EQUAL; }/* NEW in example 15 */

"<="	{ return LESS_OR_EQUAL; }	/* NEW in example 15 */

">"		{ return GREATER_THAN; }	/* NEW in example 15 */

"<"		{ return LESS_THAN; }		/* NEW in example 15 */

"#no"		{ return NOT; }				/* NEW in example 15 */

"#o"	{ return OR; }				/* NEW in example 15 */

"#y"	{ return AND; }				/* NEW in example 15 */

"{"		{ return LETFCURLYBRACKET; } 	/* NEW in example 17 */

"}"		{ return RIGHTCURLYBRACKET; }	/* NEW in example 17 */

":"		{ return COLON; }
<<EOF>> { /* The interpreter finishes when finds the end of file character */
		/*  PLACE(24,10);
	  	  std::cout <<  BICYAN;
	   	  std::cout <<  ">>>>>>> End of program <<<<<<<";
	 	  std::cout << std::endl;
	   	  std::cout << RESET;
		  PLACE(25,1);
		*/
	  	  return 0;
	}


.								{ 	
									/* Any other character */
									/* MODIFIIED in example 3 */
									/* Change to error state */
									BEGIN(ERROR); 

									/* 
										The current value of yytext 
										will be concatenated with the next character
									*/
									yymore();  
								}

<ERROR>[^0-9+\-*/()\^% \t\n\;a-zA-Z=<>!&]	{ /* MODIFIED in examples 5, 7, 15 */
								  /* NEW in example 3 */
								  /* 
									The current value of yytext 
									will be concatenated with the next character
								  */
									yymore(); 
								}

<ERROR>(.|\n)                { 
								/* NEW in example 3 */
								/* Rewind one position */
								yyless(yyleng-1); 

								/* Display the error message */
								warning("Lexical error", yytext);

								/* Restore the initial state */
   								BEGIN(INITIAL);
							}
%%

