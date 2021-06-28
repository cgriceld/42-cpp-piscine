#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("too high grade for form\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("too low grade for form\n");
}

Form::Form() : _name("default"), _sign_state(false), _grade_sign(40), _grade_exec(30) {};

Form::Form(std::string const name, int const grade_sign, int const grade_exec) : _name(name), _sign_state(false), \
_grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_exec < 1 || grade_sign < 1)
		throw GradeTooHighException();
	else if (grade_exec > 150 || grade_sign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _sign_state(copy._sign_state), \
_grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec) {};

Form::~Form() {};

Form &Form::operator = (const Form &copy)
{
	if (this != &copy)
		_sign_state = copy._sign_state;
	return (*this);
};

std::string const Form::get_name(void) const
{
	return (_name);
}

bool Form::get_state(void) const
{
	return (_sign_state);
}

int Form::get_grade_sign(void) const
{
	return (_grade_sign);
}

int Form::get_grade_exec(void) const
{
	return (_grade_exec);
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_sign_state = true;
}

std::ostream &operator << (std::ostream &stream, const Form &form)
{
	stream << "Form with name " << form.get_name() << ", sign status - " << form.get_state() << \
	", grade to sign - " << form.get_grade_sign() << " and grade to execute - " << form.get_grade_exec() << std::endl;
	return (stream);
}