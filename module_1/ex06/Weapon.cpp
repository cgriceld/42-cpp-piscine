#include "Weapon.hpp"

Weapon::Weapon() : _type("elf blade") {};

Weapon::Weapon(const std::string &type)
{
	this->_type = type;
}

Weapon::~Weapon() {};

const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(const std::string &type)
{
	this->_type = type;
}