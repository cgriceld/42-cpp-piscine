#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &copy);
	virtual ~Ice();

	Ice &operator = (const Ice &copy);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif