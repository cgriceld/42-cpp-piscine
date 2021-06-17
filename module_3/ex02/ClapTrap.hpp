#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define cancel "\033[0m"
#define yellow "\033[0;33m"
#define red "\033[0;31m"
#define green "\033[0;32m"
#define bold_green "\033[1;32m"

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const unsigned int &hit_points, const unsigned int &max_hit_points, \
	const unsigned int &energy_points, const unsigned int &max_energy_points, \
	const unsigned int &level, const unsigned int &melee_attack, \
	const unsigned int &ranged_attack, const unsigned int &armor_damage, \
	const std::string &name);
	ClapTrap(const ClapTrap &robot);
	~ClapTrap();

	ClapTrap &operator = (const ClapTrap &robot);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	virtual void set_up(void) const;

	int _hit_points;
	int _max_hit_points;
	int _energy_points;
	int _max_energy_points;
	int _level;
	int _melee_attack;
	int _ranged_attack;
	int _armor_damage;
	std::string _name;
};

#endif