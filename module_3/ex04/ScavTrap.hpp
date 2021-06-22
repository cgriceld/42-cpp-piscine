#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &robot);
	~ScavTrap();

	ScavTrap &operator = (const ScavTrap &robot);

	void rangedAttack(std::string const &target) const;
	void meleeAttack(std::string const &target) const;
	void challengeNewcomer(void);

private:
	void set_up(void) const;
	void attack(const std::string &type, const std::string &target) const;
};

#endif