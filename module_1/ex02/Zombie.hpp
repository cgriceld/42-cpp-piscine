#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie(std::string type, std::string name);
	~Zombie();

	void announce(void) const;

private:
	std::string _type;
	std::string _name;
};

#endif