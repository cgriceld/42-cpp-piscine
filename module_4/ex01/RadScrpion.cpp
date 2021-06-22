#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "Rad Scorpion")
{
	hello();
}

RadScorpion::RadScorpion(const RadScorpion &copy) : Enemy(copy)
{
	hello();
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator = (const RadScorpion &copy)
{
	if (this != &copy)
	{
		_hp = copy._hp;
		_type = copy._type;
	}
	return (*this);
}

void RadScorpion::hello(void) const
{
	std::cout << "* click click click *" << std::endl;
}