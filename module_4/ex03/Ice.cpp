#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {};

Ice::Ice(const Ice &copy) : AMateria(copy) {};

Ice &Ice::operator = (const Ice &copy)
{
	AMateria::operator=(copy);
	return (*this);
}

Ice::~Ice() {};

AMateria *Ice::clone(void) const
{
	try
	{
		AMateria *tmp = new Ice(*this);
		return (tmp);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create a copy of element\n";
		return (NULL);
	}
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
	AMateria::use(target);
}