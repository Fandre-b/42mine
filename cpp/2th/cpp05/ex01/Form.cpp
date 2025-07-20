#include "Form.hpp"

// Implementation (in cpp file)
std::ostream& operator<<(std::ostream& os, const Form& form) {
	std::cout << "teste" << std::endl; 
	return os;
}

Form::Form(const Form& other) : _name(other._name), _grade(other._grade), _isSign(other._isSign){};

Form& Form::operator=(const Form& other)
{
	if (&other != this)
	{
		this->_isSign = other._isSign;
	}
	return *this;
}

Form::Form(std::string name, int grade) : _name(name), _grade(grade), _isSign(0), _exec(0)
{
	if (this->_grade < 1)
	{
		throw GradeTooHighException("grade too high");
	}
	if (this->_grade > 150)
	{
		throw GradeTooLowException("grade too low");
	}
};

Form::Form(const Form& other) : _name(other._name). 