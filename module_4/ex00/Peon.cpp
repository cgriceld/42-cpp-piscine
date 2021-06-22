#include "Peon.hpp"

Peon::Peon() {};

Peon::Peon(const std::string &name) : Victim(name)
{
	hello();
}

Peon::Peon(const Peon &copy) : Victim(copy)
{
	hello();
};

Peon &Peon::operator = (const Peon &copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

void Peon::hello(void) const
{
	std::cout << "Zog zog.\n";
}

void Peon::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a pink pony!\n";
}