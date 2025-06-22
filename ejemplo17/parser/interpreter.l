/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/
%{
#include <iostream>
#include <cstdio>

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


std::string toLower(const std::string &str) {
	std::string result;
	for (size_t i = 0; i < str.length(); ++i)
		result += std::tolower(static_cast<unsigned char>(str[i]));
	return result;
}




%}


/*! \name REGULAR DEFINITIONS  */

DIGIT  [0-9] 

LETTER [a-zA-Z]

NUMBER1 {DIGIT}+\.?

NUMBER2 {DIGIT}*\.{DIGIT}+

IDENTIFIER {LETTER}({LETTER}|{DIGIT}|_)*



CADENA \'([^\\\']|\\[nt'\\])*\'

/* NEW in example 3 */
/* STATE  */
%x ERROR
%x COMMENT
%x BAD_IDENTIFIER


/*! \name REGULAR EXPRESSIONS  */
%%

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

":"		{ return COLON; }


","		{
			/* NEW in example 14 */
			return COMMA;
		}

"#".*	{
			/*Ignora la linea*/
		}

"(*"	{
			BEGIN(COMMENT);
		}

<COMMENT>"*)"	{BEGIN(INITIAL); }
<COMMENT>"\n"	{lineNumber++; }
<COMMENT>. 		{/*Ignora el resto*/}

{NUMBER1}|{NUMBER2}  {
					  /* MODIFIED in example 4 */
					  /* Conversion of type and sending of the numerical value to the parser */
					   yylval.number = atof(yytext); 

                       return NUMBER; 
                      }


{IDENTIFIER} {
	std::string lexema = toLower(yytext);

	// Validación del identificador
	if (lexema[0] == '_') {
		std::string mensaje = "Bad identifier: \"" + lexema + "\" (empieza con '_')";
		warning("Error léxico", mensaje.c_str());
	}
	else if (lexema[lexema.length()-1] == '_') {
		std::string mensaje = "Bad identifier: \"" + lexema + "\" (termina con '_')";
		warning("Error léxico", mensaje.c_str());
	}
	else if (lexema.find("__") != std::string::npos) {
		std::string mensaje = "Bad identifier: \"" + lexema + "\" (contiene '__')";
		warning("Error léxico", mensaje.c_str());
	}

	// Si es válido
	else
	{
		yylval.string = strdup(lexema.c_str());

		if (lexema == "mod") return MODULO;
		if (lexema == "not") return NOT;
		if (lexema == "or") return OR;
		if (lexema == "and") return AND;

		if (!table.lookupSymbol(lexema)) {
			lp::NumericVariable *n = new lp::NumericVariable(lexema, VARIABLE, UNDEFINED, 0.0);
			table.installSymbol(n);
			return VARIABLE;
		} else {
			lp::Symbol *s = table.getSymbol(lexema);
			return s->getToken();
		}
	}
}








"-"		{ return MINUS;  } 			/* NEW in example 3 */
"+"		{ return PLUS;   } 			/* NEW in example 3 */

"*"	    { return MULTIPLICATION; } 	/* NEW in example 3 */
"/"     { return DIVISION; } 		/* NEW in example 3 */
"//"	{ return FLOOR_DIVISION; }

"("     { return LPAREN; } 			/* NEW in example 3 */
")"	    { return RPAREN; } 			/* NEW in example 3 */



"^"	    { return POWER; }			/* NEW in example 5 */

":=" 	{ return ASSIGNMENT; }		/* NEW in example 7 */


"="	{ return EQUAL; }			/* NEW in example 15 */

"<>"	{ return NOT_EQUAL; }		/* NEW in example 15 */

">="	{ return GREATER_OR_EQUAL; }/* NEW in example 15 */

"<="	{ return LESS_OR_EQUAL; }	/* NEW in example 15 */

">"		{ return GREATER_THAN; }	/* NEW in example 15 */

"<"		{ return LESS_THAN; }		/* NEW in example 15 */

"{"		{ return LETFCURLYBRACKET; } 	/* NEW in example 17 */

"}"		{ return RIGHTCURLYBRACKET; }	/* NEW in example 17 */

"||"	{ return CONCATENATION; }


{CADENA} 	{std::string raw = yytext;
			raw = raw.substr(1, raw.length() - 2); // Eliminar comillas exteriores

			std::string result;
			for (size_t i = 0; i < raw.length(); ++i) {
				if (raw[i] == '\\' && i + 1 < raw.length()) {
					switch (raw[i + 1]) {
						case 'n': result += '\n'; break;
						case 't': result += '\t'; break;
						case '\'': result += '\''; break;
						case '\\': result += '\\'; break;
						default: result += raw[i + 1]; break;
					}
					++i;
				} else {
					result += raw[i];
				}
			}

			yylval.string = strdup(result.c_str());
			return STRING;}

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

<BAD_IDENTIFIER>{LETTER}|{DIGIT}|_ {
	yymore(); // seguimos acumulando el identificador erróneo
}

<BAD_IDENTIFIER>[^a-zA-Z0-9_] {
	// Terminó el identificador inválido
	yyless(1); // devuelve el carácter no perteneciente
	BEGIN(INITIAL); // vuelve al estado normal
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

