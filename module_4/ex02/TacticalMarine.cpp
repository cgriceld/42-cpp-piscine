#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	hello();
}

TacticalMarine::TacticalMarine(const TacticalMarine &copy)
{
	static_cast<void>(copy);
	hello();
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh...\n";
}

TacticalMarine &TacticalMarine::operator = (const TacticalMarine &copy)
{
	static_cast<void>(copy);
	return (*this);
}

void TacticalMarine::hello(void) const
{
	std::cout << "Tactical Marine ready for battle!\n";
}

ISpaceMarine *TacticalMarine::clone(void) const
{
	try
	{
		ISpaceMarine *tmp = new TacticalMarine(*this);
		return (tmp);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create a copy of element\n";
		return (NULL);
	}
}

void TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!\n";
}

void TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *\n";
}

void TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *\n";
}
