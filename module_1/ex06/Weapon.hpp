#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(const std::string &type);
	~Weapon();

	const std::string &getType(void) const;
	void setType(const std::string &type);

private:
	std::string _type;
};

#endif