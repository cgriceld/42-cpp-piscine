#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	hello();
}

SuperMutant::SuperMutant(const SuperMutant &copy) : Enemy(copy)
{
	hello();
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant &SuperMutant::operator = (const SuperMutant &copy)
{
	if (this != &copy)
	{
		_hp = copy._hp;
		_type = copy._type;
	}
	return (*this);
}

void SuperMutant::takeDamage(int amount)
{
	if (amount - 3 <= 0 || !_hp)
		return;
	_hp -= amount - 3;
	if (_hp < 0)
		_hp = 0;
}

void SuperMutant::hello(void) const
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}