#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("too high grade exception\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade exception\n");
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(70) {};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {};

Bureaucrat::~Bureaucrat() {};

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &copy)
{
	if (this != &copy)
		_grade = copy._grade;
	return (*this);
};

std::string const Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incr(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decr(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator << (std::ostream &stream, const Bureaucrat &copy)
{
	stream << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
	return (stream);
}