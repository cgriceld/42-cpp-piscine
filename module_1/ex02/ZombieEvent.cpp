#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zomb;

	zomb = new Zombie(this->_type, name);
	return (zomb);
}