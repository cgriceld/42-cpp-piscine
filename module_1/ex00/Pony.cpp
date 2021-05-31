#include "Pony.hpp"

Pony::Pony(std::string type) : _age(1), _name("Rocinante"), _type(type) {}

Pony::Pony(int age, std::string name, std::string type) :
	_age(age), _name(name), _type(type) {}

Pony::~Pony()
{
	std::cout << "Pony from " << this->_type << " rode away" << std::endl;
}

void Pony::introduce(void) const
{
	std::cout << "I'm from " << this->_type << " land" << std::endl;
	std::cout << this->_age << " years old, call me " << this->_name << std::endl;
}