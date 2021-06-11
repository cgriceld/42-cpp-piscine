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
	const std::string &name, const std::string &type);
	ClapTrap(const ClapTrap &robot);
	~ClapTrap();

	ClapTrap &operator = (const ClapTrap &robot);
	void intro(void) const;
	void set_up(void) const;
	void attack(std::string &type, const std::string &target) const;
	void rangedAttack(std::string const &target) const;
	void meleeAttack(std::string const &target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	unsigned int _hit_points;
	unsigned int _max_hit_points;
	unsigned int _energy_points;
	unsigned int _max_energy_points;
	unsigned int _level;
	unsigned int _melee_attack;
	unsigned int _ranged_attack;
	unsigned int _armor_damage;
	std::string _name;
	std::string _type;
};

#endif