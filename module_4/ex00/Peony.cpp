#include "Peony.hpp"

Peony::Peony() {};

Peony::Peony(const std::string &name) : Peon(name)
{
	hello();
}

Peony::Peony(const Peony &copy) : Peon(copy)
{
	hello();
};

Peony &Peony::operator = (const Peony &copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

Peony::~Peony()
{
	std::cout << "Bleuarky...\n";
}

void Peony::hello(void) const
{
	std::cout << "Zogy zogy.\n";
}

void Peony::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a red rose!\n";
}