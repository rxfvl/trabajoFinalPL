/*!	
	\file    ast.hpp
	\brief   Declaration of AST class
	\author  
	\date    2022-10-07
	\version 1.0
*/

#ifndef _AST_HPP_
#define _AST_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>


#define ERROR_BOUND 1.0e-6  //!< Error bound for the comparison of real numbers.

namespace lp
{
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*!	
  \class   ExpNode
  \brief   Definition of atributes and methods of ExpNode class
  \warning Abstract class
*/
 class ExpNode 
{
  public:
	/*!	
		\brief   Type of the expression
		\warning Pure virtual function: must be redefined in the heir classes
		\return  int
		\sa		   printAST, evaluateNumber, evaluateBool
	*/
    virtual int getType() = 0;


	/*!	
		\brief   Print the AST for expression
		\warning Pure virtual function: must be redefined in the heir classes
		\return  void
		\sa		   getType, evaluateNumber, evaluateBool
	*/
    virtual void printAST() = 0;

	/*!	
		\brief   Evaluate the expression as NUMBER
		\warning Virtual function: could be redefined in the heir classes
		\return  double
		\sa		   getType, printAST, evaluateBool
	*/
    virtual double evaluateNumber()
	{
		return 0.0;
	}

	/*!	
		\brief   Evaluate the expression as STRING
		\warning Virtual function: could be redefined in the heir classes
		\return  double
		\sa		   getType, printAST, evaluateBool,evaluateNumber
	*/
    virtual std::string evaluateString()
	{
		return "";
	}
	


	/*!	
		\brief   Evaluate the expression as BOOL
		\warning Virtual function: could be redefined in the heir classes
		\return  bool
		\sa		   getType, printAST, evaluateNumber
	*/
    virtual bool evaluateBool()
	{
		return false;
	}

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class VariableNode
  \brief Definition of atributes and methods of VariableNode class
  \note  VariableNode Class publicly inherits from ExpNode class
*/
class VariableNode : public ExpNode 
{
	private:
	  std::string _id; //!< Name of the VariableNode

	public:

	/*!		
		\brief Constructor of VariableNode
		\param value: double
		\post  A new NumericVariableNode is created with the name of the parameter
		\note  Inline function
	*/
	  VariableNode(std::string const & value)
		{
			this->_id = value; 
		}

	/*!	
		\brief   Type of the Variable
		\return  int
		\sa		   printAST
	*/
	 int getType();

	/*!
		\brief   Print the AST for Variable
		\return  void
		\sa		   getType, evaluateNumber, evaluateBool
	*/
	  void printAST();

	/*!	
		\brief   Evaluate the Variable as NUMBER
		\return  double
		\sa		   printAST
	*/
	  double evaluateNumber();

	/*!	
		\brief   Evaluate the Variable as BOOL
		\return  bool
		\sa		   getType, printAST, evaluateNumber
	*/
	  bool evaluateBool();

	/*!	
		\brief   Evaluate the Variable as String
		\return  bool
		\sa		   getType, printAST, evaluateNumber,evaluateBool
	*/
	  std::string evaluateString();

};


/*!	
  \class TernaryNode
  \brief Definition of atributes and methods of TernaryNode class
  \note  TernaryNode Class publicly inherits from ExpNode class
*/
class TernaryNode : public ExpNode 
{
private:
    ExpNode *_cond;    //!< Condition of the ternary expression
    ExpNode *_exp1;    //!< Expression for the true case
    ExpNode *_exp2;    //!< Expression for the false case

public:
    /*!		
        \brief Constructor of TernaryNode
        \param cond: pointer to ExpNode for the condition
        \param exp1: pointer to ExpNode for the true case expression
        \param exp2: pointer to ExpNode for the false case expression
        \post  A new TernaryNode is created with the parameters
        \note  Inline function
    */
    TernaryNode(ExpNode *cond, ExpNode *exp1, ExpNode *exp2)
    {
        this->_cond = cond;
        this->_exp1 = exp1;
        this->_exp2 = exp2;
    }

    /*!	
        \brief   Type of the ternary expression
        \return  int
        \sa		   printAST
    */
    int getType();

    /*!
        \brief   Print the AST for the ternary expression
        \return  void
        \sa		   getType, evaluateNumber, evaluateBool
    */
    void printAST();

    /*!	
        \brief   Evaluate the ternary expression as NUMBER
        \return  double
        \sa		   printAST
    */
    double evaluateNumber();

    /*!	
        \brief   Evaluate the ternary expression as BOOL
        \return  bool
        \sa		   getType, printAST, evaluateNumber
    */
    bool evaluateBool();

    /*!	
        \brief   Evaluate the ternary expression as String
        \return  std::string
        \sa		   getType, printAST, evaluateNumber, evaluateBool
    */
    std::string evaluateString();
};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class ConstantNode
  \brief Definition of atributes and methods of ConstantNode class
  \note  ConstantNode Class publicly inherits from ExpNode class
*/
class ConstantNode : public ExpNode 
{
	private:
	  std::string _id; //!< Name of the ConstantNode

	public:

	/*!		
		\brief Constructor of ConstantNode
		\param value: double
		\post  A new ConstantNode is created with the name of the parameter
	*/
	  ConstantNode(std::string value)
		{
			this->_id = value; 
		}

	/*!	
		\brief   Type of the Constant
		\return  int
		\sa		   printAST, evaluateNumber, evaluateBool
	*/
	 int getType();

	/*!
		\brief   Print the AST for Constant
		\return  void
		\sa		   getType, evaluateNumber, evaluateBool
	*/
	  void printAST();

	/*!	
		\brief   Evaluate the Constant as NUMBER
		\return  double
		\sa		   getType, printAST, 
	*/
	  double evaluateNumber();

	/*!	
		\brief   Evaluate the Constant as BOOL
		\return  bool
		\sa		   getType, printAST, evaluateNumber, evaluateBool
	*/
	  bool evaluateBool();
};





///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class NumberNode
  \brief Definition of atributes and methods of NumberNode class
  \note  NumberNode Class publicly inherits from ExpNode class
*/
class NumberNode : public ExpNode 
{
 private: 	
   double _number; //!< \brief number of the NumberNode
 
 public:

/*!		
	\brief Constructor of NumberNode
	\param value: double
	\post  A new NumberNode is created with the value of the parameter
	\note  Inline function
*/
  NumberNode(double value)
	{
	    this->_number = value;
	}

	/*!	
	\brief   Get the type of the expression: NUMBER
	\return  int
	\sa		   printAST, evaluateNumber
	*/
	int getType();

	/*!
		\brief   Print the AST for expression
		\return  void
		\sa		   getType, evaluateNumber
	*/
	void printAST();

	/*!	
		\brief   Evaluate the expression
		\return  double
		\sa		   getType, printAST
	*/
	double evaluateNumber();
};


/*!	
  \class StringNode
  \brief Definition of attributes and methods of StringNode class
  \note  StringNode Class publicly inherits from ExpNode class
*/
class StringNode : public ExpNode 
{
private: 	
   std::string _string; //!< String value of the StringNode
 
public:

/*!		
    \brief Constructor of StringNode
    \param value: string
    \post  A new StringNode is created with the value of the parameter
    \note  Inline function
*/
StringNode(std::string value)
{
    this->_string = value;
}

/*!	
    \brief   Get the type of the expression: STRING
    \return  int
    \sa		   printAST, evaluateString
*/
int getType();

/*!
    \brief   Print the AST for expression
    \return  void
    \sa		   getType, evaluateString
*/
void printAST();

/*!	
    \brief   Evaluate the expression
    \return  string
    \sa		   getType, printAST
*/
std::string evaluateString();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   UnaryOperatorNode
  \brief   Definition of atributes and methods of UnaryOperatorNode class
  \note    UnaryOperatorNode Class publicly inherits from ExpNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class UnaryOperatorNode : public ExpNode 
{
 protected:
  ExpNode *_exp;  //!< Child expression

 public:

/*!		
	\brief Constructor of UnaryOperatorNode links the node to it child,
           and stores the character representation of the operator.
	\param expression: pointer to ExpNode
	\post  A new OperatorNode is created with the parameters
	\note  Inline function
*/
  UnaryOperatorNode(ExpNode *expression)
	{
		this->_exp = expression;
	}

	/*!	
	\brief   Get the type of the child expression
	\return  int
	\sa		   printAST
	*/
	inline int getType()
	{
		return this->_exp->getType();
	}
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   NumericUnaryOperatorNode
  \brief   Definition of atributes and methods of UnaryOperatorNode class
  \note    UnaryOperatorNode Class publicly inherits from UnaryOperatorNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class NumericUnaryOperatorNode : public UnaryOperatorNode 
{
 public:

/*!		
	\brief Constructor of NumericUnaryOperatorNode uses UnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new NumericUnaryOperatorNode is created with the parameters
	\note  Inline function
*/
  NumericUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression)
	{
		// Empty
	}

	/*!	
	\brief   Get the type of the child expression
	\return  int
	\sa		   printAST
	*/
	int getType();

};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   LogicalUnaryOperatorNode
  \brief   Definition of atributes and methods of UnaryOperatorNode class
  \note    UnaryOperatorNode Class publicly inherits from UnaryOperatorNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class LogicalUnaryOperatorNode : public UnaryOperatorNode 
{
 public:

/*!		
	\brief Constructor of LogicalUnaryOperatorNode uses UnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new NumericUnaryOperatorNode is created with the parameters
	\note  Inline function
*/
  LogicalUnaryOperatorNode(ExpNode *expression): UnaryOperatorNode(expression)
	{
		// Empty
	}

	/*!	
	\brief   Get the type of the child expression
	\return  int
	\sa		   printAST
	*/
	int getType();

};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   UnaryMinusNode
  \brief   Definition of atributes and methods of UnaryMinusNode class
  \note    UnaryMinusNode Class publicly inherits from NumericUnaryOperatorNode class
*/
class UnaryMinusNode : public NumericUnaryOperatorNode 
{

 public:

/*!		
	\brief Constructor of UnaryMinusNode uses NumericUnaryOperatorNode's constructor as member initializer.
	\param expression: pointer to ExpNode
	\post  A new UnaryMinusNode is created with the parameter
	\note  Inline function: the NumericUnaryOperatorNode's constructor is used ad member initializer
*/
  UnaryMinusNode(ExpNode *expression): NumericUnaryOperatorNode(expression) 
	{
		// empty
	} 

/*!
	\brief   Print the AST for expression
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the expression
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*!	
  \class   UnaryPlusNode
  \brief   Definition of atributes and methods of UnaryPlusNode class
  \note    UnaryPlusNode Class publicly inherits from NumericUnaryOperatorNode class
*/
class UnaryPlusNode : public NumericUnaryOperatorNode 
{

 public:

/*!		
	\brief Constructor of UnaryPlusNode uses NumericUnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new UnaryPlusNode is created with the parameter
*/
  UnaryPlusNode(ExpNode *expression): NumericUnaryOperatorNode(expression) 
	{
		// empty
	} 

/*!
	\brief   Print the AST for expression
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the expression
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   OperatorNode
  \brief   Definition of atributes and methods of OperatorNode class
  \note    OperatorNode Class publicly inherits from ExpNode class
  \warning Abstract class, because it does not redefine the printAST and getType methods of ExpNode
*/
class OperatorNode : public ExpNode 
{
	protected:
		ExpNode *_left;    //!< Left expression
		ExpNode *_right;   //!< Right expression

	public:
	/*!		
		\brief Constructor of OperatorNode links the node to its children,
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new OperatorNode is created with the parameters
	*/
    OperatorNode(ExpNode *L, ExpNode *R)
	{
	    this->_left  = L;
    	this->_right = R;
	}

};



//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   NumericOperatorNode
  \brief   Definition of atributes and methods of NumericOperatorNode class
  \note    NumericOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class NumericOperatorNode : public OperatorNode 
{
	public:

	/*!		
		\brief Constructor of NumericOperatorNode uses OperatorNode's constructor as members initializer
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new NumericOperatorNode is created with the parameters
	*/
    NumericOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief   Get the type of the children expressions
	\return  int
	*/
	int getType();
};


/*!	
  \class   NumericOperatorNode
  \brief   Definition of atributes and methods of NumericOperatorNode class
  \note    NumericOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class StringOperatorNode : public OperatorNode 
{
	public:

	/*!		
		\brief Constructor of NumericOperatorNode uses OperatorNode's constructor as members initializer
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new NumericOperatorNode is created with the parameters
	*/
    StringOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief   Get the type of the children expressions
	\return  int
	*/
	int getType();
};
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   RelationalOperatorNode
  \brief   Definition of atributes and methods of RelationalOperatorNode class
  \note    RelationalOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class RelationalOperatorNode : public OperatorNode 
{
public:
/*!		
	\brief Constructor of RelationalOperatorNode uses OperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new RelationalOperatorNode is created with the parameters
*/
    RelationalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief   Get the type of the children expressions
	\return  int
	*/
	int getType();

};


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   LogicalOperatorNode
  \brief   Definition of atributes and methods of LogicalOperatorNode class
  \note    NumericOperatorNode Class publicly inherits from OperatorNode class
  \warning Abstract class, because it does not redefine the printAST method of ExpNode
*/
class LogicalOperatorNode : public OperatorNode 
{
	public:

	/*!		
		\brief Constructor of LogicalOperatorNode uses OperatorNode's constructor as members initializer
		\param L: pointer to ExpNode
		\param R: pointer to ExpNode
		\post  A new NumericOperatorNode is created with the parameters
	*/
    LogicalOperatorNode(ExpNode *L, ExpNode *R): OperatorNode(L,R) 
	{
		//	Empty
	}

	/*!	
	\brief   Get the type of the children expressions
	\return  int
	*/
	int getType();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   PlusNode
  \brief   Definition of atributes and methods of PlusNode class
  \note    PlusNode Class publicly inherits from NumericOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class PlusNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief Constructor of PlusNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new PlusNode is created with the parameter
*/
  PlusNode(ExpNode *L, ExpNode *R) : NumericOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for PlusNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the PlusNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

/*!	
  \class ConcatNode
  \brief Definition of attributes and methods of ConcatNode class
  \note  ConcatNode Class publicly inherits from StringOperatorNode class
         and adds its own printAST and evaluate functions
*/
class ConcatNode : public StringOperatorNode 
{
public:
/*!		
	\brief Constructor of ConcatNode uses StringOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new ConcatNode is created with the parameters
*/
  ConcatNode(ExpNode *L, ExpNode *R) : StringOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for ConcatNode
	\return  void
	\sa		   evaluateString
*/
  void printAST();

/*!	
	\brief   Evaluate the ConcatNode
	\return  string
	\sa		   printAST
*/
  std::string evaluateString();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   MinusNode
  \brief   Definition of atributes and methods of MinusNode class
  \note    MinusNode Class publicly inherits from NumericOperatorNode class 
		       and adds its own printAST and evaluate functions
*/
class MinusNode : public NumericOperatorNode 
{
  public:

/*!		
	\brief Constructor of MinusNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new MinusNode is created with the parameter
*/
  MinusNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   printAST the MinusNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the MinusNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   MultiplicationNode
  \brief   Definition of atributes and methods of MultiplicationNode class
  \note    MultiplicationNode Class publicly inherits from NumericOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class MultiplicationNode : public NumericOperatorNode 
{
  public:

/*!		
	\brief Constructor of MultiplicationNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new MultiplicationNode is created with the parameter
*/
  MultiplicationNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   printAST the MultiplicationNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the MultiplicationNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   DivisionNode
  \brief   Definition of atributes and methods of DivisionNode class
  \note    DivisionNode Class publicly inherits from NumericOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class DivisionNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief Constructor of DivisionNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new DivisionNode is created with the parameter
*/
  DivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   printAST the DivisionNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the DivisionNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

/*!	
  \class IntDivisionNode
  \brief Definition of attributes and methods of IntDivisionNode class
  \note  IntDivisionNode Class publicly inherits from NumericOperatorNode class 
         and adds its own printAST and evaluate functions
*/
class IntDivisionNode : public NumericOperatorNode 
{
public:
/*!		
	\brief Constructor of IntDivisionNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new IntDivisionNode is created with the parameters
*/
  IntDivisionNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Print the AST for IntDivisionNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the IntDivisionNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   ModuloNode
  \brief   Definition of atributes and methods of ModuloNode class
  \note    ModuloNode Class publicly inherits from NumericOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class ModuloNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief Constructor of ModuloNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new ModuloNode is created with the parameter
*/
  ModuloNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   printAST the ModuloNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the ModuloNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   PowerNode
  \brief   Definition of atributes and methods of PowerNode class
  \note    PowerNode Class publicly inherits from NumericOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class PowerNode : public NumericOperatorNode 
{
  public:
/*!		
	\brief Constructor of PowerNode uses NumericOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new PowerNode is created with the parameter
*/
  PowerNode(ExpNode *L, ExpNode *R): NumericOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for PowerNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!	
	\brief   Evaluate the PowerNode
	\return  double
	\sa		   printAST
*/
  double evaluateNumber();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode
  \brief   Definition of atributes and methods of BuiltinFunctionNode class
  \note    BuiltinFunctionNode Class publicly inherits from ExpNode class 
*/
class BuiltinFunctionNode : public ExpNode 
{
  protected: 
	std::string _id; //!< Name of the BuiltinFunctionNode
	
  public:
/*!		
	\brief Constructor of BuiltinFunctionNode
	\param id: string, name of the BuiltinFunction
	\post  A new BuiltinFunctionNode is created with the parameter
*/
  BuiltinFunctionNode(std::string id)
	{
		this->_id = id;
	}

};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode_0
  \brief   Definition of atributes and methods of BuiltinFunctionNode_0 class
  \note    BuiltinFunctionNode_0 Class publicly inherits from BuiltinFunctionNode class 
		   and adds its own printAST and evaluate functions
*/
class BuiltinFunctionNode_0 : public BuiltinFunctionNode 
{
  public:
/*!		
	\brief Constructor of BuiltinFunctionNode_0 uses BuiltinFunctionNode's constructor as member initializer
	\param id: string, name of the BuiltinFunction
	\post  A new BuiltinFunctionNode_2 is created with the parameter
*/
  BuiltinFunctionNode_0(std::string id): BuiltinFunctionNode(id)
	{
		// 
	}

	/*!	
		\brief   Get the type of the child expression:
		\return  int
		\sa		   printAST, evaluateNumber
	*/
	int getType();



	/*!
		\brief   Print the AST for BuiltinFunctionNode_0
		\return  void
		\sa		   getType, evaluateNumber
	*/
	  void printAST();

	/*!	
		\brief   Evaluate the BuiltinFunctionNode_0
		\return  double
		\sa		   getType, printAST
	*/
	  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode_1
  \brief   Definition of atributes and methods of BuiltinFunctionNode_1 class
  \note    BuiltinFunctionNode_1 Class publicly inherits from BuiltinFunctionNode class 
		   and adds its own printAST and evaluate functions
*/
class BuiltinFunctionNode_1: public BuiltinFunctionNode 
{
  private:
	ExpNode *_exp;  //!< Argument of the BuiltinFunctionNode_1

  public:
/*!		
	\brief Constructor of BuiltinFunctionNode_1 uses BuiltinFunctionNode's constructor as member initializer
	\param id: string, name of the BuiltinFunction
	\param expression: pointer to ExpNode, argument of the BuiltinFunctionNode_1
	\post  A new BuiltinFunctionNode_1 is created with the parameters
*/
  BuiltinFunctionNode_1(std::string id, ExpNode *expression): BuiltinFunctionNode(id)
	{
		this->_exp = expression;
	}

	/*!	
		\brief   Get the type of the child expression:
		\return  int
		\sa		   printAST, evaluateNumber
	*/
	int getType();

	/*!
		\brief   Print the AST for BuiltinFunctionNode_1
		\return  void
		\sa		   getType, evaluateNumber
	*/
	  void printAST();

	/*!	
		\brief   Evaluate the BuiltinFunctionNode_1
		\return  double
		\sa		   getType, printAST
	*/
	  double evaluateNumber();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   BuiltinFunctionNode_2
  \brief   Definition of atributes and methods of BuiltinFunctionNode_2 class 
  \note    BuiltinFunctionNode_2 Class publicly inherits from BuiltinFunctionNode class 
		   and adds its own printAST and evaluate functions
*/
class BuiltinFunctionNode_2 : public BuiltinFunctionNode 
{
	private:
		ExpNode *_exp1; //!< First argument of the BuiltinFunction_2
		ExpNode *_exp2; //!< Second argument of the BuiltinFunction_2

	public:
	/*!		
		\brief Constructor of BuiltinFunctionNode_2 uses BuiltinFunctionNode's constructor as member initializer
		\param id: string, name of the BuiltinFunction_2
		\param expression1: pointer to ExpNode, first argument of the BuiltinFunctionNode
		\param expression2: pointer to ExpNode, second argument of the BuiltinFunctionNode
		\post  A new BuiltinFunctionNode_2 is created with the parameters
	*/
	  BuiltinFunctionNode_2(std::string id,ExpNode *expression1,ExpNode *expression2): BuiltinFunctionNode(id)
	{
		this->_exp1 = expression1;
		this->_exp2 = expression2;
	}

	/*!	
	\brief   Get the type of the children expressions
	\return  int
	\sa		   printAST. evaluateNumber
	*/
	int getType();



	/*!
		\brief   Print the AST for BuiltinFunctionNode_2
		\return  void
		\sa		   getType, evaluateNumber
	*/
	  void printAST();

	/*!	
		\brief   Evaluate the BuiltinFunctionNode_2
		\return  double
		\sa		   getType, printAST
	*/
	  double evaluateNumber();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   GreaterThanNode
  \brief   Definition of atributes and methods of GreaterThanNode class
  \note    GreaterThanNode Class publicly inherits from RelationalOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class GreaterThanNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief Constructor of GreaterThanNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new GreaterThanNode is created with the parameter
*/
  GreaterThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }


/*!
	\brief   Print the AST for GreaterThanNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the GreaterThanNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   GreaterOrEqualNode
  \brief   Definition of atributes and methods of GreaterOrEqualNode class
  \note    GreaterOrEqualNode Class publicly inherits from RelationalOperatorNode class 
		       and adds its own printAST and evaluate functions
*/
class GreaterOrEqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief Constructor of GreaterOrEqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new GreaterOrEqualNode is created with the parameter
*/
  GreaterOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Print the AST for GreaterOrEqualNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the GreaterOrEqualNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   LessThanNode
  \brief   Definition of atributes and methods of LessThanNode class
  \note    LessThanNode Class publicly inherits from RelationalOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class LessThanNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief Constructor of LessThanNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new LessThanNode is created with the parameter
*/
  LessThanNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }
/*!
	\brief   Print the AST for LessThanNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the LessThanNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   LessOrEqualNode
  \brief   Definition of atributes and methods of LessOrEqualNode class
  \note    LessThanNode Class publicly inherits from RelationalOperatorNode class 
		       and adds its own printAST and evaluate functions
*/
class LessOrEqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief Constructor of LessOrEqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new LessOrEqualNode is created with the parameter
*/
  LessOrEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for LessOrEqualNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the LessOrEqualNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   EqualNode
  \brief   Definition of atributes and methods of EqualNode class
  \note    EqualNode Class publicly inherits from RelationalOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class EqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief Constructor of EqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new EqualNode is created with the parameter
*/
  EqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for EqualNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the EqualNode
	\return  bool
	\sa		  printAST
*/
  bool evaluateBool();;
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   NotEqualNode
  \brief   Definition of atributes and methods of NotEqualNode class
  \note    NotEqualNode Class publicly inherits from RelationalOperatorNode class 
		   and adds its own printAST and evaluate functions
*/
class NotEqualNode : public RelationalOperatorNode 
{
  public:

/*!		
	\brief Constructor of NotEqualNode uses RelationalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new NotEqualNode is created with the parameter
*/
  NotEqualNode(ExpNode *L, ExpNode *R): RelationalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for NotEqualNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the NotEqualNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   AndNode
  \brief   Definition of atributes and methods of AndNode class
  \note    AndNode Class publicly inherits from LogicalOperatorNode class 
		       and adds its own printAST and evaluate functions
*/
class AndNode : public LogicalOperatorNode 
{
  public:

/*!		
	\brief Constructor of AndNode uses LogicalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new AndNode is created with the parameter
*/
  AndNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for AndNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the AndNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   OrNode
  \brief   Definition of atributes and methods of OrNode class
  \note    OrNode Class publicly inherits from LogicalOperatorNode class 
		       and adds its own printAST and evaluate functions
*/
class OrNode : public LogicalOperatorNode 
{
  public:

/*!		
	\brief Constructor of AndNode uses LogicalOperatorNode's constructor as members initializer
	\param L: pointer to ExpNode
	\param R: pointer to ExpNode
	\post  A new AndNode is created with the parameter
*/
  OrNode(ExpNode *L, ExpNode *R): LogicalOperatorNode(L,R) 
  {
		// Empty
  }

/*!
	\brief   Print the AST for OrNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the OrNode
	\return  bool
	\sa		 printAST()
*/
  bool evaluateBool();
};



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*!	
  \class   NotNode
  \brief   Definition of atributes and methods of UnaryPlusNode class
  \note    NotNode Class publicly inherits from LogicalUnaryOperatorNode class
*/
class NotNode : public LogicalUnaryOperatorNode 
{

 public:

/*!		
	\brief Constructor of NotNode uses LogicalUnaryOperatorNode's constructor as member initializer
	\param expression: pointer to ExpNode
	\post  A new NotNode is created with the parameter
*/
  NotNode(ExpNode *expression): LogicalUnaryOperatorNode(expression) 
	{
		// empty
	} 

/*!
	\brief   Print the AST for NotNode
	\return  void
	\sa		   evaluateBool
*/
  void printAST();

/*!	
	\brief   Evaluate the NotNode
	\return  bool
	\sa		   printAST
*/
  bool evaluateBool();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   Statement
  \brief   Definition of atributes and methods of Statement class
  \warning Abstract class
*/

class Statement {
 public:

/*!	
	\brief   Print the AST for Statement
	\note    Virtual function: can be redefined in the heir classes
	\return  double
	\sa		   evaluate
*/

  virtual void printAST() {}

/*!	
	\brief   Evaluate the Statement
	\warning Pure virtual function: must be redefined in the heir classes
	\return  double
	\sa		   printAST
*/
  virtual void evaluate() = 0;
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   AssignmentStmt
  \brief   Definition of atributes and methods of AssignmentStmt class
  \note    AssignmentStmt Class publicly inherits from Statement class 
		   and adds its own printAST and evaluate functions
*/
class AssignmentStmt : public Statement 
{
 private:
  std::string _id; //!< Name of the variable of the assignment statement
  ExpNode *_exp; 	 //!< Expresssion the assignment statement

  AssignmentStmt *_asgn;  //!< Allow multiple assigment -> a = b = 2 

 public:

/*!		
	\brief Constructor of AssignmentStmt 
	\param id: string, variable of the AssignmentStmt
	\param expression: pointer to ExpNode
	\post  A new AssignmentStmt is created with the parameters
*/
  AssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
	{
		this->_asgn = NULL; 
	}

/*!		
	\brief Constructor of AssignmentStmt 
	\param id: string, variable of the AssignmentStmt
	\param asgn: pointer to AssignmentStmt
	\post  A new AssignmentStmt is created with the parameters
	\note  Allow multiple assigment -> a = b = 2 
*/

  AssignmentStmt(std::string id, AssignmentStmt *asgn): _id(id), _asgn(asgn)
	{
		this->_exp = NULL;
	}


/*!
	\brief   Print the AST for AssignmentStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the AssignmentStmt
	\return  void
	\sa		   printAST
*/
    void evaluate();

};


/*!	
  \class   PlusAssignmentStmt
  \brief   Definition of attributes and methods of PlusAssignmentStmt class
  \note    PlusAssignmentStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class PlusAssignmentStmt : public Statement 
{
private:
  std::string _id; //!< Name of the variable of the assignment statement
  ExpNode *_exp;   //!< Expression of the assignment statement

public:
/*!		
    \brief Constructor of PlusAssignmentStmt 
    \param id: string, variable of the AssignmentStmt
    \param expression: pointer to ExpNode
    \post  A new PlusAssignmentStmt is created with the parameters
*/
  PlusAssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
  {
		
  }

/*!
    \brief   Print the AST for PlusAssignmentStmt
    \return  void
    \sa      evaluate
*/
  void printAST();

/*!	
    \brief   Evaluate the PlusAssignmentStmt
    \return  void
    \sa      printAST
*/
  void evaluate();
};

/*!	
  \class   MinusAssignmentStmt
  \brief   Definition of attributes and methods of MinusAssignmentStmt class
  \note    MinusAssignmentStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class MinusAssignmentStmt : public Statement 
{
private:
  std::string _id; //!< Name of the variable of the assignment statement
  ExpNode *_exp;   //!< Expression of the assignment statement

public:
/*!		
    \brief Constructor of MinusAssignmentStmt 
    \param id: string, variable of the AssignmentStmt
    \param expression: pointer to ExpNode
    \post  A new MinusAssignmentStmt is created with the parameters
*/
  MinusAssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
  {
		
  }

/*!
    \brief   Print the AST for MinusAssignmentStmt
    \return  void
    \sa      evaluate
*/
  void printAST();

/*!	
    \brief   Evaluate the MinusAssignmentStmt
    \return  void
    \sa      printAST
*/
  void evaluate();
};

/*!	
  \class   MultAssignmentStmt
  \brief   Definition of attributes and methods of MultAssignmentStmt class
  \note    MultAssignmentStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class MultAssignmentStmt : public Statement 
{
private:
  std::string _id; //!< Name of the variable of the assignment statement
  ExpNode *_exp;   //!< Expression of the assignment statement

public:
/*!		
    \brief Constructor of MultAssignmentStmt 
    \param id: string, variable of the AssignmentStmt
    \param expression: pointer to ExpNode
    \post  A new MultAssignmentStmt is created with the parameters
*/
  MultAssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
  {
		
  }

/*!
    \brief   Print the AST for MultAssignmentStmt
    \return  void
    \sa      evaluate
*/
  void printAST();

/*!	
    \brief   Evaluate the MultAssignmentStmt
    \return  void
    \sa      printAST
*/
  void evaluate();
};

/*!	
  \class   DivAssignmentStmt
  \brief   Definition of attributes and methods of DivAssignmentStmt class
  \note    DivAssignmentStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class DivAssignmentStmt : public Statement 
{
private:
  std::string _id; //!< Name of the variable of the assignment statement
  ExpNode *_exp;   //!< Expression of the assignment statement

public:
/*!		
    \brief Constructor of DivAssignmentStmt 
    \param id: string, variable of the AssignmentStmt
    \param expression: pointer to ExpNode
    \post  A new DivAssignmentStmt is created with the parameters
*/
  DivAssignmentStmt(std::string id, ExpNode *expression): _id(id), _exp(expression)
  {
		
  }

/*!
    \brief   Print the AST for DivAssignmentStmt
    \return  void
    \sa      evaluate
*/
  void printAST();

/*!	
    \brief   Evaluate the DivAssignmentStmt
    \return  void
    \sa      printAST
*/
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

/*!	
  \class   PrintStmt
  \brief   Definition of atributes and methods of PrintStmt class
  \note    PrintStmt Class publicly inherits from Statement class 
		   and adds its own print and evaluate functions
  \warning  In this class, printAST and evaluate functions have the same meaning.
*/
class PrintStmt: public Statement 
{
 private:
  ExpNode *_exp; //!< Expresssion the print statement

 public:
/*!		
	\brief Constructor of PrintStmt 
	\param expression: pointer to ExpNode
	\post  A new PrintStmt is created with the parameter
*/
  PrintStmt(ExpNode *expression)
	{
		this->_exp = expression;
	}

/*!
	\brief   Print the AST for PrintStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the PrintStmt
	\return  double
	\sa		   printAST
*/
  void evaluate();
};


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   ReadStmt
  \brief   Definition of atributes and methods of ReadStmt class
  \note    ReadStmt Class publicly inherits from Statement class 
		   and adds its own printAST and evaluate functions
*/
class ReadStmt : public Statement 
{
  private:
	std::string _id; //!< Name of the ReadStmt
	

  public:
/*!		
	\brief Constructor of ReadStmt
	\param id: string, name of the variable of the ReadStmt
	\post  A new ReadStmt is created with the parameter
*/
  ReadStmt(std::string id)
	{
		this->_id = id;
	}

/*!
	\brief   Print the AST for ReadStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the ReadStmt
	\return  void
	\sa		   printAST
*/
  void evaluate();
};

/*!	
  \class   ReadStringStmt
  \brief   Definition of attributes and methods of ReadStringStmt class
  \note    ReadStringStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class ReadStringStmt : public Statement 
{
private:
	std::string _id; //!< Name of the variable of the ReadStmt
	
public:
/*!		
	\brief Constructor of ReadStringStmt
	\param id: string, name of the variable of the ReadStmt
	\post  A new ReadStringStmt is created with the parameter
*/
  ReadStringStmt(std::string id)
	{
		this->_id = id;
	}

/*!
	\brief   Print the AST for ReadStringStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the ReadStringStmt
	\return  void
	\sa		   printAST
*/
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   EmptyStmt
  \brief   Definition of atributes and methods of EmptyStmt class
  \note    EmptyStmt Class publicly inherits from Statement class 
		   and adds its own printAST and evaluate functions
*/
class EmptyStmt : public Statement 
{
  // No attributes

  public:
/*!		
	\brief Constructor of  WhileStmt
	\post  A new EmptyStmt is created 
*/
  EmptyStmt()
	{
		// Empty
	}


/*!
	\brief   Print the AST for EmptyStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the EmptyStmt
	\return  void
	\sa		   printAST
*/
  void evaluate();
};



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

/*!	
  \class   IfStmt
  \brief   Definition of atributes and methods of IfStmt class
  \note    IfStmt Class publicly inherits from Statement class 
		       and adds its own printAST and evaluate functions
*/
class IfStmt : public Statement 
{
 private:
  ExpNode *_cond;    //!< Condicion of the if statement
  Statement *_stmt1; //!< Statement of the consequent
  Statement *_stmt2; //!< Statement of the alternative

  public:
/*!		
	\brief Constructor of Single IfStmt (without alternative)
	\param condition: ExpNode of the condition
	\param statement1: Statement of the consequent
	\post  A new IfStmt is created with the parameters
*/
  IfStmt(ExpNode *condition, Statement *statement1)
	{
		this->_cond = condition;
		this->_stmt1 = statement1;
		this->_stmt2 = NULL;
	}


/*!		
	\brief Constructor of Compound IfStmt (with alternative)
	\param condition: ExpNode of the condition
	\param statement1: Statement of the consequent
	\param statement2: Statement of the alternative
	\post  A new IfStmt is created with the parameters
*/
  IfStmt(ExpNode *condition, Statement *statement1, Statement *statement2)
	{
		this->_cond = condition;
		this->_stmt1 = statement1;
		this->_stmt2 = statement2;
	}


/*!
	\brief   Print the AST for IfStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the IfStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};





///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

/*!	
  \class   WhileStmt
  \brief   Definition of atributes and methods of WhileStmt class
  \note    WhileStmt Class publicly inherits from Statement class 
		       and adds its own printAST and evaluate functions
*/
class WhileStmt : public Statement 
{
 private:
  ExpNode *_cond; //!< Condicion of the while statement
  Statement *_stmt; //!< Statement of the body of the while loop

  public:
/*!		
	\brief Constructor of  WhileStmt
	\param condition: ExpNode of the condition
	\param statement: Statement of the body of the loop 
	\post  A new WhileStmt is created with the parameters
*/
  WhileStmt(ExpNode *condition, Statement *statement)
	{
		this->_cond = condition;
		this->_stmt = statement;
	}


/*!
	\brief   Print the AST for WhileStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the WhileStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};
/*!	
  \class   WhileStmt
  \brief   Definition of atributes and methods of WhileStmt class
  \note    WhileStmt Class publicly inherits from Statement class 
		       and adds its own printAST and evaluate functions
*/

class DoWhileStmt : public Statement 
{
 private:
  ExpNode *_cond; //!< Condicion of the while statement
  Statement *_stmt; //!< Statement of the body of the while loop

  public:
/*!		
	\brief Constructor of  WhileStmt
	\param condition: ExpNode of the condition
	\param statement: Statement of the body of the loop 
	\post  A new WhileStmt is created with the parameters
*/
  DoWhileStmt(ExpNode *condition, Statement *statement)
	{
		this->_cond = condition;
		this->_stmt = statement;
	}


/*!
	\brief   Print the AST for WhileStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the WhileStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};
/*!	
  \class   ForStmt
  \brief   Definition of attributes and methods of ForStmt class
  \note    ForStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class ForStmt : public Statement 
{
private:
  std::string _var; //!< Name of the loop variable
  ExpNode *_inf_lim; //!< Initial value of the loop variable
  ExpNode *_sup_lim; //!< Upper limit of the loop variable
  ExpNode *_paso; //!< Step value for the loop variable
  Statement *_stmt; //!< Statement of the body of the for loop

public:
/*!		
	\brief Constructor of ForStmt
	\param var: string, name of the loop variable
	\param inf_lim: pointer to ExpNode, initial value of the loop variable
	\param sup_lim: pointer to ExpNode, upper limit of the loop variable
	\param statement: pointer to Statement, statement of the body of the loop 
	\param paso: pointer to ExpNode (optional), step value for the loop variable
	\post  A new ForStmt is created with the parameters
*/
  ForStmt(std::string var, ExpNode *inf_lim, ExpNode *sup_lim, Statement *statement, ExpNode *paso = NULL)
	{
		this->_var = var;
		this->_inf_lim = inf_lim;
		this->_sup_lim = sup_lim;
		this->_paso = paso;
		this->_stmt = statement;
	}

/*!
	\brief   Print the AST for ForStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the ForStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};

/*!	
  \class   RepeatStmt
  \brief   Definition of attributes and methods of RepeatStmt class
  \note    RepeatStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class RepeatStmt : public Statement 
{
private:
  Statement *_stmt; //!< Statement of the body of the repeat loop
  ExpNode *_cond; //!< Condition of the repeat statement

public:
/*!		
	\brief Constructor of RepeatStmt
	\param statement: pointer to Statement, statement of the body of the loop 
	\param cond: pointer to ExpNode, condition of the repeat loop
	\post  A new RepeatStmt is created with the parameters
*/
  RepeatStmt(Statement *statement, ExpNode *cond)
	{
		this->_cond = cond;
		this->_stmt = statement;
	}

/*!
	\brief   Print the AST for RepeatStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the RepeatStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};

/*!	
  \class   ClearStmt
  \brief   Definition of attributes and methods of ClearStmt class
  \note    ClearStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class ClearStmt : public Statement 
{
public:
/*!		
	\brief Constructor of ClearStmt
	\post  A new ClearStmt is created
*/
  ClearStmt() {}

/*!
	\brief   Print the AST for ClearStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the ClearStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};

/*!	
  \class   PlaceStmt
  \brief   Definition of attributes and methods of PlaceStmt class
  \note    PlaceStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class PlaceStmt : public Statement 
{
private:
  ExpNode *_exp1; //!< First expression for placement
  ExpNode *_exp2; //!< Second expression for placement

public:
/*!		
	\brief Constructor of PlaceStmt
	\param exp1: pointer to ExpNode, first expression for placement
	\param exp2: pointer to ExpNode, second expression for placement
	\post  A new PlaceStmt is created with the parameters
*/
  PlaceStmt(ExpNode *exp1, ExpNode *exp2)
	{
		this->_exp1 = exp1;
		this->_exp2 = exp2;
	}

/*!
	\brief   Print the AST for PlaceStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the PlaceStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};

/*!	
  \class   UniformNode
  \brief   Definition of attributes and methods of UniformNode class
  \note    UniformNode Class publicly inherits from ExpNode class
*/
class UniformNode : public ExpNode
{
private:
  ExpNode *_exp1; //!< Lower bound expression
  ExpNode *_exp2; //!< Upper bound expression

public:
/*!		
	\brief Constructor of UniformNode
	\param exp1: pointer to ExpNode, lower bound expression
	\param exp2: pointer to ExpNode, upper bound expression
	\post  A new UniformNode is created with the parameters
*/
  UniformNode(ExpNode *exp1, ExpNode *exp2)
	{
		this->_exp1 = exp1;
		this->_exp2 = exp2;
	}

/*!
	\brief   Print the AST for UniformNode
	\return  void
	\sa		   evaluateNumber
*/
  void printAST();

/*!
	\brief   Get the type of the expression: NUMBER
	\return  int
*/
  int getType();

/*!	
	\brief   Evaluate the UniformNode as NUMBER
	\return  double
*/
  double evaluateNumber();
};

/*!	
  \class   CaseStmt
  \brief   Definition of attributes and methods of CaseStmt class
  \note    CaseStmt Class publicly inherits from Statement class 
		   and adds its own printAST and evaluate functions
*/
class CaseStmt : public Statement 
{
private:
	ExpNode *_expv; //!< Expression for the case
	Statement *_stmt; //!< Statement for the case

public:
/*!		
	\brief Constructor of CaseStmt
	\param expv: pointer to ExpNode, expression for the case
	\param statement: pointer to Statement, statement of the body of the case 
	\post  A new CaseStmt is created with the parameters
*/
  CaseStmt(ExpNode *expv, Statement *statement)
	{
		this->_expv = expv;
		this->_stmt = statement;
	}

/*!
	\brief   Print the AST for CaseStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the CaseStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();

/*!	
	\brief   Get the expression associated with the case
	\return  ExpNode*
*/
  ExpNode *getExp()
  {
    return this->_expv;
  }
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

/*!	
  \class   BlockStmt
  \brief   Definition of atributes and methods of BlockStmt class
  \note    BlockStmt Class publicly inherits from Statement class 
		       and adds its own printAST and evaluate functions
*/
class BlockStmt : public Statement 
{
 private:
   std::list<Statement *> *_stmts;  //!< List of statements

  public:
/*!		
	\brief Constructor of  BlockStmt
	\param stmtList: list of Statement
	\post  A new BlockStmt is created with the parameters
*/
  BlockStmt(std::list<Statement *> *stmtList): _stmts(stmtList)
	{
		// Empty
	}


/*!
	\brief   Print the AST for BlockStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the BlockStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};

/*!	
  \class   CaseBlockStmt
  \brief   Definition of attributes and methods of CaseBlockStmt class
  \note    CaseBlockStmt Class publicly inherits from Statement class 
           and adds its own printAST and evaluate functions
*/
class CaseBlockStmt : public Statement 
{
private:
	ExpNode *_exp; //!< Expression for the case block
    std::list<CaseStmt *> *_cases; //!< List of case statements
    Statement *_def;  //!< Default statement

public:
/*!		
	\brief Constructor of CaseBlockStmt
	\param exp: pointer to ExpNode, expression for the case block
	\param caseList: pointer to std::list<CaseStmt *>, list of case statements
	\param def: pointer to Statement, default statement
	\post  A new CaseBlockStmt is created with the parameters
*/
  CaseBlockStmt(ExpNode *exp, std::list<CaseStmt *> *caseList, Statement *def)
	{
		this->_cases = caseList;
		this->_exp = exp;
		this->_def = def;
	}

/*!
	\brief   Print the AST for CaseBlockStmt
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   Evaluate the CaseBlockStmt
	\return  void
	\sa	   	 printAST
*/
  void evaluate();
};

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


/*!	
  \class   AST
  \brief   Definition of atributes and methods of AST class
*/
class AST {
 private:
  std::list<Statement *> *stmts;  //!< List of statements

 public:

/*!		
	\brief Constructor of PrintStmt 
	\param stmtList: pointer to a list of pointers to Statement
	\post  A new PrintStmt is created with the parameter
*/
  AST(std::list<Statement *> *stmtList): stmts(stmtList)
	{
		// Empty
	}

/*!
	\brief   print the AST
	\return  void
	\sa		   evaluate
*/
  void printAST();

/*!	
	\brief   evaluate the AST
	\return  double
	\sa	   	 printAST
*/
  void evaluate();
};

// End of name space lp
}



// End of _AST_HPP_
#endif




