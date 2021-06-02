#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <string>
#include <iostream>

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde();

	void announce(void) const;

private:
	Zombie *_wave;
	int _n;
};

#endif