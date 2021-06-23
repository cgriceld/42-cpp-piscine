#include "Clicker.hpp"

Clicker::Clicker() : Enemy(30, "Clicker")
{
	hello();
}

Clicker::Clicker(const Clicker &copy) : Enemy(copy)
{
	hello();
}

Clicker::~Clicker()
{
	std::cout << "clicker is dead" << std::endl;
}

Clicker &Clicker::operator = (const Clicker &copy)
{
	if (this != &copy)
	{
		_hp = copy._hp;
		_type = copy._type;
	}
	return (*this);
}

void Clicker::hello(void) const
{
	std::cout << "*some creepy noises around the corner*" << std::endl;
}

void Clicker::takeDamage(int amount)
{
	if (amount - 2 <= 0 || !_hp)
		return;
	_hp -= amount - 2;
	if (_hp < 0)
		_hp = 0;
}