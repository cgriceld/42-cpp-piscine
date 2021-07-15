#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern;

typedef struct	s_type
{
	std::string name;
	Form *(Intern::*create)(const std::string &target) const;
}				t_type;

class Intern
{
public:

	Intern();
	Intern(const Intern &copy);
	virtual ~Intern();

	Intern &operator = (const Intern &copy);

	Form *makeForm(const std::string &type, const std::string &target) const;

private:

	Form *create_shrub(const std::string &target) const;
	Form *create_rob(const std::string &target) const;
	Form *create_pardon(const std::string &target) const;

	static const t_type types[3];
};

#endif