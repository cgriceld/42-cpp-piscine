#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	set_target("default");
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	set_target(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy)
{
	set_target(copy.get_target());
}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		Form::operator = (copy);
		set_target(copy.get_target());
	}
	return (*this);
};

void RobotomyRequestForm::action(void) const
{
	std::cout << "* drilling noises *\n";
	std::rand() % 2 ? std::cout << get_target() << " has been robotomized successfully\n" : \
	std::cout << "failed to robotomized " << get_target() << std::endl;
}