#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* mar = new AssaultTerminator;
	ISpaceMarine* ine = new TacticalMarine;
	ISquad* vlc = new Squad;
	Squad dflt;
	Squad copy(dflt);
	std::cout << "-------------------\n";

	vlc->push(bob);
	std::cout << vlc->push(jim) << std::endl;
	vlc->push(jim);
	vlc->push(NULL);
	vlc->push(mar);
	vlc->push(ine);
	std::cout << vlc->getCount() << std::endl;
	std::cout << "-------------------\n";

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "-------------------\n";

	std::cout << vlc->getUnit(21) << std::endl;
	delete vlc;

	return (0);
}