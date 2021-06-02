#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon) : _name(name), _weapon(weapon) {};

HumanA::~HumanA() {};

void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}