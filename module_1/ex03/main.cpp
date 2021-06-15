#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde wave(10);
	wave.announce();
	std::cout << std::endl;

	ZombieHorde wave2(5);
	wave2.announce();
	std::cout << std::endl;

	return (0);
}