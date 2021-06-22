#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &robot);
	virtual ~FragTrap();

	FragTrap &operator = (const FragTrap &robot);

	virtual void rangedAttack(std::string const &target) const;
	virtual void meleeAttack(std::string const &target) const;
	void vaulthunter_dot_exe(std::string const &target);

private:
	void set_up(void) const;
	void attack(const std::string &type, const std::string &target) const;
};

#endif