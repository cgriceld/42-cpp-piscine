#ifndef CROSSBOW_HPP
# define CROSSBOW_HPP

#include "AWeapon.hpp"
#include <iostream>

class Crossbow : public AWeapon
{
public:
	Crossbow();
	Crossbow(const Crossbow &copy);
	virtual ~Crossbow();

	Crossbow &operator = (const Crossbow &copy);

	void attack(void) const;
};

#endif