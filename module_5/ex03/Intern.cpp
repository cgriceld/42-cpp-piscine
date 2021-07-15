#include "Intern.hpp"

const t_type Intern::types[3] = \
{
	{"shrubbery creation", &Intern::create_shrub},
	{"robotomy request", &Intern::create_rob},
	{"presidential pardon", &Intern::create_pardon}
};

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
		std::cerr << e.what() << ": can't create new shrubbery; returns null\n";
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
		std::cerr << e.what() << ": can't create new robotomy request; returns null\n";
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
		std::cerr << e.what() << ": can't create new presidential pardon; returns null\n";
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
	std::cout << "Not a valid form name, try again; returns null\n";
	return (NULL);
}