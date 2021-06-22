#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Pumpkin.hpp"
#include "Peony.hpp"

int main(void)
{
	{
		Sorcerer robert("Robert", "the Magnificent");
		std::cout << "------------------------\n";
		Victim jim("Jimmy");
		std::cout << "------------------------\n";
		Peon joe("Joe");
		std::cout << "------------------------\n";

		std::cout << robert << jim << joe;
		std::cout << "------------------------\n";

		robert.polymorph(jim);
		robert.polymorph(joe);
		std::cout << "------------------------\n";
	}
	std::cout << "\n PART 2\n\n";
	{
		Victim *victim = new Victim("Jack");
		std::cout << "------------------------\n";
		Victim *peon = new Peon("Sam");
		std::cout << "------------------------\n";
		Victim *pumpkin = new Pumpkin("Ben");
		std::cout << "------------------------\n";
		Victim *peony = new Peony("Samy");
		std::cout << "------------------------\n";

		std::cout << *victim << *peon << *pumpkin << *peony;
		std::cout << "------------------------\n";

		Victim *base[] = {victim, peon, peony, pumpkin};
		for (int i = 0; i < 4; i++)
			base[i]->getPolymorphed();
		std::cout << "------------------------\n";

		delete victim;
		delete peon;
		delete pumpkin;
		delete peony;
	}
	return (0);
}