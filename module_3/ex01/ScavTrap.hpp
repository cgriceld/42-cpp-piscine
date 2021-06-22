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

	void rangedAttack(std::string const &target) const;
	void meleeAttack(std::string const &target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);

private:
	void set_up(void) const;
	void attack(const std::string &type, const std::string &target) const;

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