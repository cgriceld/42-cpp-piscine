#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("too high grade for bureaucrat\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade for bureaucrat\n");
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

void Bureaucrat::signForm(Form &form) const
{
	if (form.get_state())
	{
		std::cout << "Form " << form.get_name() << " already signed\n";
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.get_name() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << _name << " cannot sign " << form.get_name() << " because " \
		<< e.what();
	}
}

std::ostream &operator << (std::ostream &stream, const Bureaucrat &bur)
{
	stream << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return (stream);
}