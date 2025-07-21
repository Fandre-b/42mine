#include "Bureaucrat.hpp"

int main()
{
	try
	{
		// throw std::exception();
		Bureaucrat bureaucrat;
		Bureaucrat bureaucrat2("John", 1);
		bureaucrat2++;
		bureaucrat2++;

	}
	catch(const std::runtime_error& e)
	{
		// I can do this because runtime_error is a subclass of exception
		std::cout << e.what() << std::endl;
	}
	// catch (const GradeTooHighException& e) {
	// 	std::cout << "Grade too high: " << e.what() << std::endl;
	// }
	// catch (const GradeTooLowException& e) {
	// 	std::cout << "Grade too low: " << e.what() << std::endl;
	// }
	catch (const std::exception& e) {
		std::cout << "Some other exception: " << e.what() << std::endl;
	}
	
	// bureaucrat.incrementGrade();
	// std::cout << bureaucrat << std::endl;
	// return 0;
}

Bureaucrat::~Bureaucrat()
{};


Bureaucrat::Bureaucrat(Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	this->checkGrade();
};

int Bureaucrat::getGrade() const
{ 
	//Const makes sure fn does not modify members
	// Also const obj can only call const fn
	return this->_grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

//implementing operators

// Bureaucrat& Bureaucrat::operator++()
// {
//     this->_grade--;
//     return *this;
// }

Bureaucrat Bureaucrat::operator++(int)
{
	// Bureaucrat temp = *this;
	this->_grade--;
	this->checkGrade();
	return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
	// Bureaucrat temp = *this;
	this->_grade++;
	this->checkGrade();
	return *this;
}

void Bureaucrat::checkGrade()
{
	if (this->_grade < 1)
	{
		throw GradeTooHighException("grade too high");
	}
	if (this->_grade > 150)
	{
		throw GradeTooLowException("grade too low");
	}
}



// Implementation (in cpp file)
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	std::cout << "teste" << std::endl; 
	return os;
}