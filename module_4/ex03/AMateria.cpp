#include "AMateria.hpp"

AMateria::AMateria() {};

AMateria::AMateria(const std::string &type) : _xp(0), _type(type) {};

AMateria::AMateria(const AMateria &copy) : _xp(copy._xp), _type(copy._type) {};

AMateria &AMateria::operator = (const AMateria &copy)
{
	if (this != &copy)
		_xp = copy._xp;
	return (*this);
}

AMateria::~AMateria() {};

std::string const &AMateria::getType(void) const
{
	return (_type);
}

unsigned int AMateria::getXP(void) const
{
	return (_xp);
}

void AMateria::use(ICharacter& target)
{
	_xp += 10;
	static_cast<void>(target);
}