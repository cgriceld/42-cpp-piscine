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
	return (new TacticalMarine(*this));
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
