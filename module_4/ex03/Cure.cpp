#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {};

Cure::Cure(const Cure &copy) : AMateria(copy) {};

Cure &Cure::operator = (const Cure &copy)
{
	AMateria::operator=(copy);
	return (*this);
}

Cure::~Cure() {};

AMateria *Cure::clone(void) const
{
	try
	{
		AMateria *tmp = new Cure(*this);
		return (tmp);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create a copy of element\n";
		return (NULL);
	}
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
	AMateria::use(target);
}