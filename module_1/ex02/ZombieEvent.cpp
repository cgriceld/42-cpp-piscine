#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : _type("sleepy")
{
	srand(time(0));
};

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

	try
	{
		zomb = new Zombie(this->_type, name);
	}
	catch (const std::bad_alloc &ba)
	{
		std::cerr << "No space for new zombie : " << ba.what() << std::endl;
		zomb = NULL;
	}
	return (zomb);
}