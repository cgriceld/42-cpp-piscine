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
	void challengeNewcomer();
};

#endif