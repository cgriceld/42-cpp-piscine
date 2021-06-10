#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>

#define cancel "\033[0m"
#define yellow "\033[0;33m"
#define red "\033[0;31m"
#define green "\033[0;32m"
#define bold_green "\033[1;32m"

class ScavTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &robot);
	~ScavTrap();

	ScavTrap &operator = (const ScavTrap &robot);
	void intro(void) const;
	void set_up(void) const;
	void attack(std::string &type, const std::string &target) const;
	void rangedAttack(std::string const &target) const;
	void meleeAttack(std::string const &target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer();

private:
	unsigned int _hit_points;
	unsigned int _max_hit_points;
	unsigned int _energy_points;
	unsigned int _max_energy_points;
	unsigned int _level;
	unsigned int _melee_attack;
	unsigned int _ranged_attack;
	unsigned int _armor_damage;
	std::string _name;
};

#endif