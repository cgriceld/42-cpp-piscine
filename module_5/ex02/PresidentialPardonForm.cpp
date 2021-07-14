#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
	set_target("default");
};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	set_target(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy)
{
	set_target(copy.get_target());
}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		Form::operator = (copy);
		set_target(copy.get_target());
	}
	return (*this);
};

void PresidentialPardonForm::action(void) const
{
	std::cout << get_target() << " has been pardoned by Zafod Beeblebrox\n";
}