#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {};

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy) : AWeapon(copy) {};

PlasmaRifle::~PlasmaRifle() {};

PlasmaRifle &PlasmaRifle::operator = (const PlasmaRifle &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apcost = copy._apcost;
		_damage = copy._damage;
	}
	return (*this);
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}