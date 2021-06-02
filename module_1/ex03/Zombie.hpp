#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string type, std::string name);
	~Zombie();

	void announce() const;
	void set_name(std::string name);

private:
	std::string _type;
	std::string _name;
};

#endif