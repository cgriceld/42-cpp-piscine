#include "Zombie.hpp"

Zombie::Zombie() : _type("agressive"), _name("runner") {};

Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name) {};

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_type << " " << this->_name << " is dead now...kind of..." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}