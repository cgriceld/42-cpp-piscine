#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {};

HumanB::~HumanB() {};

void HumanB::attack(void) const
{
	if (!this->_weapon)
		std::cout << "No weapon set yet for " << this->_name << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}