#include "Pumpkin.hpp"

Pumpkin::Pumpkin() {};

Pumpkin::Pumpkin(const std::string &name) : Victim(name)
{
	hello();
}

Pumpkin::Pumpkin(const Pumpkin &copy) : Victim(copy)
{
	hello();
};

Pumpkin &Pumpkin::operator = (const Pumpkin &copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

Pumpkin::~Pumpkin()
{
	std::cout << "Exactly at 12 o'clock...\n";
}

void Pumpkin::hello(void) const
{
	std::cout << "Trick or treat!\n";
}

void Pumpkin::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a carriage!\n";
}