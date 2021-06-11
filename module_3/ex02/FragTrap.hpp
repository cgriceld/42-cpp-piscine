#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &robot);
	~FragTrap();

	FragTrap &operator = (const FragTrap &robot);
	void vaulthunter_dot_exe(std::string const &target);
};

#endif