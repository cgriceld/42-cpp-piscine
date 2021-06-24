#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &copy);
	virtual ~Cure();

	Cure &operator = (const Cure &copy);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif