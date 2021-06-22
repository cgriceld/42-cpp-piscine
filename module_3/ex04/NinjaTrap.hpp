#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(const std::string &name);
	NinjaTrap(const NinjaTrap &robot);
	virtual ~NinjaTrap();

	NinjaTrap &operator = (const NinjaTrap &robot);

	virtual void rangedAttack(std::string const &target) const;
	virtual void meleeAttack(std::string const &target) const;
	void ninjaShoebox(ClapTrap &target) const;
	void ninjaShoebox(FragTrap &target) const;
	void ninjaShoebox(ScavTrap &target) const;
	void ninjaShoebox(NinjaTrap &target) const;

private:
	void set_up(void) const;
	void attack(const std::string &type, const std::string &target) const;
	void no_power(void) const;
};

#endif