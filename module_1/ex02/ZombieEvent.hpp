#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent();
	~ZombieEvent();

	void	setZombieType(std::string);
	void	randomChump(void) const;
	Zombie*	newZombie(std::string name) const;

private:
	std::string _type;
};

#endif