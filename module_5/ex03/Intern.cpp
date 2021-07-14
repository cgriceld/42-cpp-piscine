#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &copy)
{
	static_cast<void>(copy);
}

Intern::~Intern() {};

Intern &Intern::operator = (const Intern &copy)
{
	static_cast<void>(copy);
	return (*this);
};

Form *Intern::create_shrub(const std::string &target) const
{
	try
	{
		Form *form = new ShrubberyCreationForm(target);
		return (form);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create new shrubbery\n";
		return (NULL);
	}
}

Form *Intern::create_rob(const std::string &target) const
{
	try
	{
		Form *form = new RobotomyRequestForm(target);
		return (form);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create new robotomy request\n";
		return (NULL);
	}
}

Form *Intern::create_pardon(const std::string &target) const
{
	try
	{
		Form *form = new PresidentialPardonForm(target);
		return (form);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create new presidential pardon\n";
		return (NULL);
	}
}

Form *Intern::makeForm(const std::string &type, const std::string &target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (!types[i].name.compare(type))
		{
			std::cout << "Intern creates " << type << std::endl;
			return (this->*types[i].create)(target);
		}
	}
	std::cout << "Not a valid form name, try again\n";
	return (NULL);
}