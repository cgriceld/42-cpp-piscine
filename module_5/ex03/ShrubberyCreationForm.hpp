#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &copy);

private:
	ShrubberyCreationForm();

	void action(void) const;
};

#endif