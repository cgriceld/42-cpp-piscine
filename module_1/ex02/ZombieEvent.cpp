#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : _type("sleepy") {};

ZombieEvent::~ZombieEvent() {};

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

void ZombieEvent::randomChump(void) const
{
	std::string names[6] = {"runner", "stalker", "clicker", "bloater", "shambler", "rat king"};
	Zombie Shon(this->_type, names[rand() % 6]);
	Shon.announce();
}

Zombie* ZombieEvent::newZombie(std::string name) const
{
	Zombie *zomb;

	zomb = new Zombie(this->_type, name);
	return (zomb);
}