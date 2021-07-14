#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
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

	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	virtual ~Bureaucrat();

	Bureaucrat &operator = (const Bureaucrat &copy);

	std::string const getName(void) const;
	int getGrade(void) const;

	void incr(void);
	void decr(void);
	void signForm(Form &form) const;
	void executeForm(Form const &form) const;

private:
	Bureaucrat();

	std::string const _name;
	int _grade;
};

std::ostream &operator << (std::ostream &stream, const Bureaucrat &bur);

#endif