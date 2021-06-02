#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const std::string &name, const Weapon &weapon);
	~HumanA();

	void attack(void) const;

private:
	std::string _name;
	const Weapon &_weapon;
};

#endif