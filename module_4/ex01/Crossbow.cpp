#include "Crossbow.hpp"

Crossbow::Crossbow() : AWeapon("Crossbow", 40, 75) {};

Crossbow::Crossbow(const Crossbow &copy) : AWeapon(copy) {};

Crossbow::~Crossbow() {};

Crossbow &Crossbow::operator = (const Crossbow &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apcost = copy._apcost;
		_damage = copy._damage;
	}
	return (*this);
}

void Crossbow::attack(void) const
{
	std::cout << "* whoosh *" << std::endl;
}