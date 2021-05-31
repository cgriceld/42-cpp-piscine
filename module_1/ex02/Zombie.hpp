#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie(std::string type, std::string name) : _type(type), _name(name) {};
	~Zombie() {};

	void announce() const;

private:
	std::string _type;
	std::string _name;
};

#endif