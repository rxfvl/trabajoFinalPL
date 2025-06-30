/*! 
  \file   stringVariable.hpp
  \brief  Declaration of StringVariable class
*/

#ifndef _STRINGVARIABLE_HPP_
#define _STRINGVARIABLE_HPP_

#include "variable.hpp"
#include <string>

namespace lp {

/*!	
  \class  StringVariable
  \brief  Definition of a string variable
*/
class StringVariable : public lp::Variable {
 private:
	std::string _value; //!< Value of the string variable

 public:
	using Variable::operator=;
	/*!		
		\brief Constructor
		\param name: variable identifier
		\param token: symbol type (should be VARIABLE)
		\param type: data type (e.g. -1 for string)
		\param value: initial value
	*/
	StringVariable(std::string name, int token, int type, std::string value)
		: Variable(name, token, type), _value(value) {}

	/*!	
		\brief Return the value of the variable
		\return string
	*/
	inline std::string getValue() const { return _value; }

	/*!	
		\brief Set the value of the variable
		\param value: new string value
	*/
	inline void setValue(const std::string &value) { _value = value; }
};

} // namespace lp

#endif // _STRINGVARIABLE_HPP_
