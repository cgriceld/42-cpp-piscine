#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _n(N)
{
	std::string names[6] = {"runner", "stalker", "clicker", "bloater", "shambler", "rat king"};
	try
	{
		this->_wave = new Zombie[_n];
		for (int i = 0; i < this->_n; i++)
			this->_wave[i].set_name(names[rand() % 6]);
	}
	catch (const std::bad_alloc &ba)
	{
		std::cerr << ba.what() << std::endl;
		this->_wave = NULL;
	}
}

void ZombieHorde::announce(void) const
{
	if (!this->_wave)
	{
		std::cout << "No horde was allocated" << std::endl;
		return;
	}
	for (int i = 0; i < this->_n; i++)
		this->_wave[i].announce();
}

ZombieHorde::~ZombieHorde()
{
	if (this->_wave)
	{
		delete[] this->_wave;
		std::cout << "Wave passed!" << std::endl;
	}
}