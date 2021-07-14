#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
#include <fstream>

class PresidentialPardonForm : public Form
{
public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator = (const PresidentialPardonForm &copy);

private:
	PresidentialPardonForm();

	void action(void) const;
};

#endif