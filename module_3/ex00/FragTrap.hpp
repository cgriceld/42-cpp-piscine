#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>

#define cancel "\033[0m"
#define yellow "\033[0;33m"
#define red "\033[0;31m"
#define green "\033[0;32m"
#define bold_green "\033[1;32m"

class FragTrap
{
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &robot);
	~FragTrap();

	FragTrap &operator = (const FragTrap &robot);
	void intro(void) const;
	void rangedAttack(std::string const &target) const;
	void meleeAttack(std::string const &target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);

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