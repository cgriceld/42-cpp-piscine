#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	srand(time(0));

	ZombieHorde wave(10);
	wave.announce();
	std::cout << std::endl;

	return (0);
}