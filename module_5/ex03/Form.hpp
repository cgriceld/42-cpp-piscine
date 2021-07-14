#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
public:

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	Form(std::string const name, int const _grade_sign, int const _grade_exec);
	Form(const Form &copy);
	virtual ~Form();

	Form &operator = (const Form &copy);

	std::string const get_name(void) const;
	bool get_state(void) const;
	int get_grade_sign(void) const;
	int get_grade_exec(void) const;
	std::string get_target(void) const;
	void set_target(std::string target);
	
	void beSigned(const Bureaucrat &bur);
	void execute(Bureaucrat const &executor) const;

private:
	Form();
	virtual void action(void) const = 0;

	std::string const _name;
	bool _sign_state;
	int const _grade_sign;
	int const _grade_exec;
	std::string _target;
};

std::ostream &operator << (std::ostream &stream, const Form &form);

#endif