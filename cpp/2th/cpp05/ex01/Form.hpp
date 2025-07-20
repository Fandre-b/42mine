
#include <string>
#include <iostream>

class Form
{
	private:
		const std::string _name;
		const int _grade;
		int _isSign;
		int _exec;

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();

		Form(std::string name, int grade);
		void beSigned();
};

std::ostream& operator<<(std::ostream& os, const Form& bureaucrat);


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

