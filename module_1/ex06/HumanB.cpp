#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name) {};

HumanB::~HumanB() {};

void HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon(const Weapon &weapon)
{
	this->_weapon = weapon;
}