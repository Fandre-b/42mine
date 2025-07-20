#include <string>
#include <iostream>

class Bureaucrat 
{
	private:
		const std::string _name;
		int _grade;
	public:
		// Contructors
		Bureaucrat() : _name("default"), _grade(0){};
		virtual ~Bureaucrat();
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		Bureaucrat(std::string name, int grade);
		
		std::string getName() const;
		int getGrade() const;
		
		// Bureaucrat& operator++(); // ++bureaucrat
		Bureaucrat operator++(int); //bureaucrat++
		// Bureaucrat& operator--();
		Bureaucrat operator--(int);
		// void increment();
		// void decrease();
		// overload&«(); //
		// borucract;

		void checkGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

class Form
{
	private:
		const std::string _name;
		int _isSign;
		int _exec;
		int _grade;

	public:
		void beSigned();
};

class GradeTooHighException : public std::runtime_error
{
	public:
		GradeTooHighException(std::string msg) : runtime_error(msg){};
};

class GradeTooLowException : public std::runtime_error
{
	public:
		GradeTooLowException(std::string msg) : runtime_error(msg){};
};