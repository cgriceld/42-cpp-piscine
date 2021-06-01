#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void)
{
	Zombie Shon("agressive", "clicker");
	Shon.announce();
	std::cout << std::endl;

	ZombieEvent Frank;
	Zombie *Paul = Frank.newZombie("runner");
	Paul->announce();
	delete Paul;
	std::cout << std::endl;

	Frank.setZombieType("agressive");
	Zombie *Tom = Frank.newZombie("bloater");
	Tom->announce();
	delete Tom;
	std::cout << std::endl;

	srand(time(0));

	Frank.randomChump();
	std::cout << std::endl;
	Frank.randomChump();
	std::cout << std::endl;
	Frank.randomChump();
	std::cout << std::endl;
	Frank.randomChump();
	std::cout << std::endl;

	return (0);
}