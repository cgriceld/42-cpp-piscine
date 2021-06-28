#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
#include <fstream>

class RobotomyRequestForm : public Form
{
public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator = (const RobotomyRequestForm &copy);

	void action(void) const;

private:
	RobotomyRequestForm();
};

#endif