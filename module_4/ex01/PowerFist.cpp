#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {};

PowerFist::PowerFist(const PowerFist &copy) : AWeapon(copy) {};

PowerFist::~PowerFist() {};

PowerFist &PowerFist::operator = (const PowerFist &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apcost = copy._apcost;
		_damage = copy._damage;
	}
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}