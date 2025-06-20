/*!	
	\file    ast.cpp
	\brief   Code of funcitons of AST clas
	\author  
	\date    2018-12-13
	\version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <random>

// Para usar la funciones pow y std::abs
#include <cmath>

#include "ast.hpp"

#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

// 
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/stringVariable.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"

#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"
#include <cstring>


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols


extern lp::AST *root; //!< Reference to the object at the base of the AST


///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType() 
{ 
	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Return the type of the Variable
	return var->getType();
}


void lp::VariableNode::printAST() 
{
  std::cout << "VariableNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


double lp::VariableNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the variable is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::VariableNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalVariable
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);

		// Copy the value of the LogicalVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}

std::string lp::VariableNode::evaluateString() 
{ 
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::StringVariable *var = (lp::StringVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the variable is not string", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


int lp::TernaryNode::getType() 
{ 
	// Get the identifier in the table of symbols as Variable
	if(this->_cond->evaluateBool()){
		return this->_exp1->getType();
	}
	else{
		return this->_exp2->getType();
	}
	

	// Return the type of the Variable
}



void lp::TernaryNode::printAST() 
{
  std::cout << "TernaryNode: ";
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


double lp::TernaryNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		

		// Copy the value of the NumericVariable
		if(this->_cond->evaluateBool()){
			result = this->_exp1->evaluateNumber();
		}
		else{
			result =  this->_exp2->evaluateNumber();
		}
	}
	else
	{
		warning("Runtime error in evaluateNumber():"," the expression is not numeric");
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::TernaryNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_cond->evaluateBool()){
			result = this->_exp1->evaluateBool();
		}
		else{
			result =  this->_exp2->evaluateBool();
		}
	}
	else
	{
		warning("Runtime error in evaluateNumber():"," the expression is not boolean");
	}

	// Return the value of the LogicalVariable
	return result;
}

std::string lp::TernaryNode::evaluateString() 
{ 
	std::string result = "";

	if (this->getType() == STRING)
	{
		if(this->_cond->evaluateBool()){
			result = this->_exp1->evaluateString();
		}
		else{
			result =  this->_exp2->evaluateString();
		}
	}
	else
	{
		warning("Runtime error in evaluateNumber():"," the expression is not string");
	}

	// Return the value of the NumericVariable
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstantNode::printAST() 
{
  std::cout << "ConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

int lp::ConstantNode::getType() 
{ 
	// Get the identifier in the table of symbols as Constant
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);

	// Return the type of the Constant
	return var->getType();
}


double lp::ConstantNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the constant is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}

bool lp::ConstantNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
 

int lp::NumberNode::getType()
{
	return NUMBER;
}


void lp::NumberNode::printAST()
{
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber() 
{ 
    return this->_number; 
}



int lp::StringNode::getType()
{
	return STRING;
}


void lp::StringNode::printAST()
{
  std::cout << "StringNode: " << this->_string << std::endl;
}

std::string lp::StringNode::evaluateString() 
{ 
    return this->_string; 
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::NumericUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == NUMBER)
	{
		result = NUMBER;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == BOOL)
	{
		result = BOOL;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}
	
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}

int lp::StringOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = STRING;
	else
		warning("Runtime error: incompatible types for", "String Operator");

	return	result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::RelationalOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = BOOL;
	else if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
		result = BOOL;
	else if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = BOOL;
	else
		warning("Runtime error: incompatible types for", "Relational Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode:: getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
	{
		// 
		result = BOOL;
	}
	else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryMinusNode::printAST() 
{
  std::cout << "UnaryMinusNode: -"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryMinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Minus
		result = - this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPlusNode::printAST() 
{
  std::cout << "UnaryPlusNode: +"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryPlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::printAST() 
{
  std::cout << "PlusNode: +"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}

void lp::ConcatNode::printAST() 
{
  std::cout << "StringNode: ||"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

std::string lp::ConcatNode::evaluateString()
{
	std::string result = "";

	// Ckeck the types of the expressions
	if (this->getType() == STRING)
	{
		result = this->_left->evaluateString() + this->_right->evaluateString();
	}
	else
	{
		warning("Runtime error: the expressions are not string for ", "Concatenate");
	}

  return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::printAST() 
{
  std::cout << "MinusNode: -"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MinusNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::MultiplicationNode::printAST() 
{
  std::cout << "MultiplicationNode: *"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MultiplicationNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::printAST()
{
  std::cout << "DivisionNode: /" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::DivisionNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}

void lp::IntDivisionNode::printAST()
{
  std::cout << "IntDivisionNode: //" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::IntDivisionNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result =(double) ((int)leftNumber / (int)rightNumber);
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::printAST()
{
  std::cout << "ModuloNode: %" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::ModuloNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
    	if(std::abs(rightNumber) > ERROR_BOUND)
				result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::printAST() 
{
  std::cout << "PowerNode: **"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PowerNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
	return	NUMBER;
}


void lp::BuiltinFunctionNode_0::printAST() 
{
  std::cout << "BuiltinFunctionNode_0: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}

double lp::BuiltinFunctionNode_0::evaluateNumber() 
{
	// Get the identifier in the table of symbols as BuiltinParameter0
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);

	// Apply the function and copy the result
   	return f->getFunction()();
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
	int result = 0;
		
	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::printAST() 
{
  std::cout << "BuiltinFunctionNode_1: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;  
  std::cout << "\t";
	this->_exp->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_1::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter1
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);

		// Apply the function to the parameter and copy the result
		result = f->getFunction()(this->_exp->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
	int result = 0;
		
	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

	return	result;
}


void lp::BuiltinFunctionNode_2::printAST() 
{
  std::cout << "BuiltinFunctionNode_2: " << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";
  this->_exp1->printAST();
  std::cout << "\t";
	this->_exp2->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_2::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter2
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);

		// Apply the function to the parameters and copy the result
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::printAST()
{
  std::cout << "GreaterThanNode: >" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType()==NUMBER){
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber > rightNumber);
		}
		else if(this->_left->getType()==STRING){
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();
			result = (strcmp(leftString.c_str(), rightString.c_str())>0);
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::printAST()
{
  std::cout << "GreaterOrEqualNode: >= " << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType()==NUMBER){
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber >= rightNumber);
		}
		else if(this->_left->getType()==STRING){
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();
			result = (strcmp(leftString.c_str(), rightString.c_str())>=0);
		}
	}
	
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::printAST()
{
  std::cout << "LessThanNode: <" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if (this->_left->getType()==NUMBER){
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber < rightNumber);
		}
		else if(this->_left->getType()==STRING){
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();
			result = (strcmp(leftString.c_str(), rightString.c_str())<0);
		}
	}
	
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::printAST()
{
  std::cout << "LessOrEqualNode: <=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType()==NUMBER){
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber <= rightNumber);
		}
		else if(this->_left->getType()==STRING){
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();
			result = (strcmp(leftString.c_str(), rightString.c_str())<=0);
		}
	}
	
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::printAST()
{
  std::cout << "EqualNode: ==" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::EqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) < ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean == rightBoolean);
			break;
			case STRING: {
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();
				result = (strcmp(leftString.c_str(), rightString.c_str())==0);}
			break;
		
			default:
					warning("Runtime error: incompatible types of parameters for ", 
									"Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", 
						"Equal operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::printAST()
{
  std::cout << "NotEqualNode: !=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::NotEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) >= ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean != rightBoolean);
				break;
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Not Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Not Equal operator");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::printAST()
{
  std::cout << "AndNode: &&" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::AndNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::printAST()
{
  std::cout << "OrNode: ||" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::OrNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::printAST()
{
  std::cout << "NotNode: !" << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
}

bool lp::NotNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		result = not this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////





void lp::AssignmentStmt::printAST() 
{
  std::cout << "assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::AssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value 
					lp::NumericVariable *v = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,value);
					table.installSymbol(v);
				}
			}
			break;

			case BOOL:
			{
				bool value;
				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateBool();

				if (firstVar->getType() == BOOL)
				{
				  	// Get the identifier in the table of symbols as LogicalVariable
					lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not BOOL
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value 
					lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,value);
					table.installSymbol(v);
				}
			}
			break;
			case STRING:
			{
				std::string value;
				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateString();

				if (firstVar->getType() == STRING)
				{
				  	// Get the identifier in the table of symbols as LogicalVariable
					lp::StringVariable *v = (lp::StringVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not BOOL
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type STRING and the value 
					lp::StringVariable *v = new lp::StringVariable(this->_id,
											VARIABLE,STRING,value);
					table.installSymbol(v);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == NUMBER)
				{
				/* Get the identifier of the first variable in the table of symbols as NumericVariable */
				lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value of the previous variable 
					lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case BOOL:
			{
				/* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
				lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == BOOL)
				{
				/* Get the identifier of the first variable in the table of symbols as LogicalVariable */
				lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not BOOL
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value of the previous variable 
					lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}
	}
}
void lp::PlusAssignmentStmt::printAST() 
{
  std::cout << "plusassignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  

}

void lp::PlusAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber() ;

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(v->getValue()+value);
				}
				// The type of variable is not NUMBER
				else
				{
					execerror("Error en el operador \':+=\', la variable no está declarada", "PlusAssignmentStmt::evaluate()");
				}
			}
			break;

			case BOOL:
			{
				execerror("Error en el operador \':+=\', el operador no permite variables tipo BOOL", "PlusAssignmentStmt::evaluate()");
			}
			break;
			case STRING:
			{
				execerror("Error en el operador \':+=\', el operador no permite variables tipo STRING", "PlusAssignmentStmt::evaluate()");
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "PlusAssigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	
}

void lp::MinusAssignmentStmt::printAST() 
{
  std::cout << "minusassignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  

}

void lp::MinusAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber() ;

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(v->getValue()-value);
				}
				// The type of variable is not NUMBER
				else
				{
					execerror("Error en el operador \':-=\', la variable no está declarada", "MinusAssignmentStmt::evaluate()");
				}
			}
			break;

			case BOOL:
			{
				execerror("Error en el operador \':-=\', el operador no permite variables tipo BOOL", "MinusAssignmentStmt::evaluate()");
			}
			break;
			case STRING:
			{
				execerror("Error en el operador \':-=\', el operador no permite variables tipo STRING", "MinusAssignmentStmt::evaluate()");
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "MinusAssigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	
}


void lp::MultAssignmentStmt::printAST() 
{
  std::cout << "multassignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  

}

void lp::MultAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber() ;

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(v->getValue()*value);
				}
				// The type of variable is not NUMBER
				else
				{
					execerror("Error en el operador \':*=\', la variable no está declarada", "MultAssignmentStmt::evaluate()");
				}
			}
			break;

			case BOOL:
			{
				execerror("Error en el operador \':*=\', el operador no permite variables tipo BOOL", "MultAssignmentStmt::evaluate()");
			}
			break;
			case STRING:
			{
				execerror("Error en el operador \':*=\', el operador no permite variables tipo STRING", "MultAssignmentStmt::evaluate()");
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "MultAssigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	
}


void lp::DivAssignmentStmt::printAST() 
{
  std::cout << "divassignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  

}

void lp::DivAssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber() ;
				if (value == 0){
					execerror("Error en el operador \':/=\', división por 0", "DivAssignmentStmt::evaluate()");
				}

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(v->getValue()/value);
				}
				// The type of variable is not NUMBER
				else
				{
					execerror("Error en el operador \':/=\', la variable no está declarada", "MultAssignmentStmt::evaluate()");
				}
			}
			break;

			case BOOL:
			{
				execerror("Error en el operador \':/=\', el operador no permite variables tipo BOOL", "MultAssignmentStmt::evaluate()");
			}
			break;
			case STRING:
			{
				execerror("Error en el operador \':/=\', el operador no permite variables tipo STRING", "MultAssignmentStmt::evaluate()");
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "MultAssigment");
		}

	}


	
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::printAST() 
{
  std::cout << "printASTStmt: printAST"  << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
  std::cout << std::endl;
}


void lp::PrintStmt::evaluate() 
{
	/*std::cout << BIYELLOW; 
	std::cout << "print: ";
	std::cout << RESET; */

	switch(this->_exp->getType())
	{
		case NUMBER:
				std::cout << this->_exp->evaluateNumber();
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "verdadero";
			else
				std::cout << "falso";
		
			break;
		case STRING:
			std::cout << this->_exp->evaluateString();
			break;
		default:
			warning("Runtime error: incompatible type for ", "escribir");
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::printAST() 
{
  std::cout << "ReadStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}

bool isNumber(const std::string& str) {
    // Comprobar si la cadena está vacía
    if (str.empty()) {
        return false;
    }

    // Comprobar cada carácter de la cadena
    for (char c : str) {
        if (!std::isdigit(c) && c!='+' && c!='-') {
            return false;
        }
    }

    return true;
}
void lp::ReadStmt::evaluate() 
{   
	double value;
	std::string svalue;
	/*std::cout << BIYELLOW; 
	std::cout << "Insert a numeric value --> " ;
	std::cout << RESET;*/
	getline(std::cin, svalue);
	if (isNumber(svalue)){
		value = (double)atof(svalue.c_str());
		/* Get the identifier in the table of symbols as Variable */
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		// Check if the type of the variable is NUMBER
		if (var->getType() == NUMBER)
		{
			/* Get the identifier in the table of symbols as NumericVariable */
			lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);
							
			/* Assignment the read value to the identifier */
			n->setValue(value);
		}
		// The type of variable is not NUMBER
		else
		{
			// Delete $1 from the table of symbols as Variable
			table.eraseSymbol(this->_id);

				// Insert $1 in the table of symbols as NumericVariable 
			// with the type NUMBER and the read value 
			lp::NumericVariable *n = new lp::NumericVariable(this->_id, 
										VARIABLE,NUMBER,value);

			table.installSymbol(n);
		}
	}
	else{
		execerror("Error en la función \"leer\", se ha introducido una cadena", "ReadStmt::evaluate");
	}

	
}

void lp::ReadStringStmt::printAST() 
{
  std::cout << "ReadStringStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}


void lp::ReadStringStmt::evaluate() 
{   
	std::string value;
	/*
	std::cout << BIYELLOW; 
	std::cout << "Insert a string value --> " ;
	std::cout << RESET;*/
	getline(std::cin, value);
	char * cv = const_cast<char*>(value.c_str());
	char* result = const_cast<char*>(value.c_str());

    int j = 0;
    bool isEscaped = false;

    for (int i = 0; cv[i] != '\0'; i++) {
		
        if (cv[i] == '\\' && !isEscaped) {
            // Si encuentra una barra invertida, marca que el siguiente carácter está escapado
            isEscaped = true;
        } else if (cv[i] == '\'' && !isEscaped) {
            // Si encuentra una comilla simple no escapada, copiarla al resultado
            continue;
        } 
		else if (isEscaped && (cv[i]=='n' || cv[i]=='t')){
			if (cv[i] == 'n') {
				result[j++] = '\n';
			} else {
				result[j++] = '\t';
			}
			i++;
            isEscaped = false;
		}
		else {
            // En cualquier otro caso, copiar el carácter al resultado
            result[j++] = cv[i];
            isEscaped = false;
        }
    }

    // Termina el resultado con un carácter nulo
    result[j] = '\0';
	value  = result;
	lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);
	
	if (n->getType() == STRING)
	{
		n->setValue(value);
	}
	else{
		lp::StringVariable *aux = new lp::StringVariable(this->_id, VARIABLE, STRING, value);
		table.eraseSymbol(aux->getName());
		table.installSymbol(aux);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::printAST() 
{
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate() 
{
  // Empty
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::IfStmt::printAST() 
{
  std::cout << "IfStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Consequent
  std::cout << "\t";
  this->_stmt1->printAST();

 // The alternative is printASTed if exists
  if (this->_stmt2 != NULL)
     {  
       std::cout << "\t";
	   this->_stmt2->printAST();
     }

  std::cout << std::endl;
}


void lp::IfStmt::evaluate() 
{
   // If the condition is true,
	if (this->_cond->evaluateBool() == true )
     // the consequent is run 
	  this->_stmt1->evaluate();

    // Otherwise, the alternative is run if exists
	else if (this->_stmt2 != NULL)
		  this->_stmt2->evaluate();
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::WhileStmt::printAST() 
{
  std::cout << "WhileStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the while loop
  std::cout << "\t";
  this->_stmt->printAST();

  std::cout << std::endl;
}


void lp::WhileStmt::evaluate() 
{
  // While the condition is true. the body is run 
  while (this->_cond->evaluateBool() == true)
  {	
	  this->_stmt->evaluate();
  }

}
void lp::DoWhileStmt::printAST() 
{
  std::cout << "DoWhileStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the while loop
  std::cout << "\t";
  this->_stmt->printAST();

  std::cout << std::endl;
}


void lp::DoWhileStmt::evaluate() 
{
  // While the condition is true. the body is run 
  do
  {	
	  this->_stmt->evaluate();
  }while (this->_cond->evaluateBool() == true);

}

void lp::ForStmt::printAST() 
{
  std::cout << "ForStmt: "  << std::endl;
  
	std::cout << "\t";
	this->_inf_lim->printAST();
	std::cout << "\t";
	this->_sup_lim->printAST();
	std::cout << "\t";
	if(this->_paso !=NULL){
		this->_paso->printAST();
	}
	std::cout << "\t";
	this->_stmt->printAST();
  std::cout << std::endl;
}


void lp::ForStmt::evaluate() 
{
	
  lp::NumericVariable *nm = (lp::NumericVariable *) table.getSymbol(this->_var);

  double ivalue, fvalue, pvalue;
  ivalue = this->_inf_lim->evaluateNumber();
  fvalue = this->_sup_lim->evaluateNumber();

  if (this->_paso == NULL){
	pvalue = 1.0;
  }
  else{
	pvalue = this->_paso->evaluateNumber();
  }
  
  nm->setValue(ivalue);

  if (nm->getType() == UNDEFINED){
			 nm->setType(NUMBER);
  }
  bool cond =true;
  bool pos_step = pvalue > 0;
  bool neg_step = pvalue < 0;
  if (pos_step){
	  cond = nm->getValue() <= fvalue;
  }
  else if (neg_step){
	  cond = nm->getValue() >= fvalue;
  }
  //Control de bucles infinitos
  if(ivalue<fvalue && pvalue<=0){
	  execerror("Error en el bucle for: Bucle infinito", "ForStmt::evaluate");
  }
  else if(ivalue>fvalue && pvalue>=0){
	  execerror("Error en el bucle for: Bucle infinito", "ForStmt::evaluate");
  }
  else if(ivalue==fvalue && pvalue==0){
	  execerror("Error en el bucle for: Bucle infinito", "ForStmt::evaluate");
  }
  while (cond)
  {	
	
	
	this->_stmt->evaluate();
	nm->setValue(nm->getValue()+pvalue);
	if(pos_step){
		if(nm->getValue()>fvalue){
			cond = false;
		}
		
	}
	else{
		if(nm->getValue()<fvalue){
			cond = false;
		}
	}
	
  }

}

void lp::RepeatStmt::printAST() 
{
  std::cout << "RepeatStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the while loop
  std::cout << "\t";
  this->_stmt->printAST();

  std::cout << std::endl;
}


void lp::RepeatStmt::evaluate() 

{
  while (this->_cond->evaluateBool() != true)
  {	
	
	this->_stmt->evaluate();
  }

}


void lp::ClearStmt::printAST() 
{
  std::cout << "ClearStmt"  << std::endl;


  std::cout << std::endl;
}


void lp::ClearStmt::evaluate() 

{
  std::cout<<CLEAR_SCREEN;
  PLACE(0,0);

}

void lp::PlaceStmt::printAST() 
{
  std::cout << "PlaceStmt"  << std::endl;
  	std::cout << "\t";
	this->_exp1->printAST();
	std::cout << "\t";
	this->_exp2->printAST();


  std::cout << std::endl;
}


void lp::PlaceStmt::evaluate() 

{
  if(this->_exp1->getType()!=this->_exp2->getType() || this->_exp1->getType()!= NUMBER){
	execerror("Error en la función \"lugar\", los tipos de los argumentos no son correctos", "PlaceStmt::evaluate");
  }
  else{
	PLACE((int)this->_exp1->evaluateNumber(),(int)this->_exp2->evaluateNumber());
  }

}

void lp::UniformNode::printAST() 
{
  std::cout << "UniformNode"  << std::endl;
  	std::cout << "\t";
	this->_exp1->printAST();
	std::cout << "\t";
	this->_exp2->printAST();


  std::cout << std::endl;
}
int lp::UniformNode::getType(){
	return NUMBER;
}

double lp::UniformNode::evaluateNumber() 

{
  if(this->_exp1->getType()!=this->_exp2->getType() || this->_exp1->getType()!= NUMBER){
	execerror("Error en la función \"uniforme\", los tipos de los argumentos no son correctos", "UniformNode::evaluateNumber");
  }
  else{
	
	double a = this->_exp1->evaluateNumber();
	double b = this->_exp2->evaluateNumber();
	std::random_device rd;  // Utilizado para inicializar el generador de números aleatorios
    std::mt19937 generator(rd());  // Generador de números aleatorios Mersenne Twister
    
	double r = 0;
	if (a>b){
		execerror("Error en la función \"uniforme\", el primer valor debe de ser menor que el segundo", "UniformNode::evaluateNumber");
	}
	std::uniform_real_distribution<double> distribution(a, b); 
	r = distribution(generator);
	return r;
	
  }

}
void lp::CaseStmt::printAST() 
{
  	std::cout << "CaseStmt"  << std::endl;
	std::cout << "\t";
	this->_expv->printAST();
	std::cout << "\t";
	this->_stmt->printAST();


  std::cout << std::endl;
}


void lp::CaseStmt::evaluate() 

{
  this->_stmt->evaluate();

}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::BlockStmt::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}


void lp::BlockStmt::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}

void lp::CaseBlockStmt::printAST() 
{
  std::list<CaseStmt *>::iterator caseIter;

  std::cout << "CaseBlockStmt: "  << std::endl;

  for (caseIter = this->_cases->begin(); caseIter != this->_cases->end(); caseIter++) 
  {
     (*caseIter)->printAST();
  }
}


void lp::CaseBlockStmt::evaluate() 
{
  std::list<CaseStmt *>::iterator caseIter;

	ExpNode * sw = this->_exp;
	bool df = true;
	if (sw->getType()==NUMBER){
		for (caseIter = this->_cases->begin(); caseIter != this->_cases->end(); caseIter++) 
		{
			
			if (sw->evaluateNumber() == (*caseIter)->getExp()->evaluateNumber()){
				(*caseIter)->evaluate();
				df = false;
			}
		}
		if (df){
			this->_def->evaluate();
		}
	}
	else if (sw->getType()==STRING){
		for (caseIter = this->_cases->begin(); caseIter != this->_cases->end(); caseIter++) 
		{
			
			if (sw->evaluateString() == (*caseIter)->getExp()->evaluateString()){
				(*caseIter)->evaluate();
				df = false;
			}
		}
		if (df){
			this->_def->evaluate();
		}
	}
	else if (sw->getType()==BOOL){
		for (caseIter = this->_cases->begin(); caseIter != this->_cases->end(); caseIter++) 
		{
			
			if (sw->evaluateBool() == (*caseIter)->getExp()->evaluateBool()){
				(*caseIter)->evaluate();
				df = false;
			}
		}
		if (df){
			this->_def->evaluate();
		}
	}
	else{
		warning("Error en tiempo de ejecución:", "Los tipos de las expresiones de casos y los valores no son los mismos");
	}
  
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}



void lp::AST::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}

