#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, "Ishikawa")
{
	std::cout << green << "ClapTrap adjusting settings depending on chosen type...wait..." << std::endl;
	this->set_up();
};

NinjaTrap::NinjaTrap(const std::string &name) : ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, name)
{
	std::cout << green << "ClapTrap adjusting settings depending on chosen type...wait..." << std::endl;
	this->set_up();
};

NinjaTrap::NinjaTrap(const NinjaTrap &robot)
{
	std::cout << bold_green << "Copying input data..." << cancel << std::endl;
	*this = robot;
	this->set_up();
}

void NinjaTrap::set_up(void) const
{
	std::cout << green << "Konnichiwa! I'm " << bold_green + _name + cancel + ".\n";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << yellow <<  _name << " : We'll meet again one day!" << cancel << std::endl;
}

NinjaTrap &NinjaTrap::operator = (const NinjaTrap &robot)
{
	this->_hit_points = robot._hit_points;
	this->_max_hit_points = robot._max_hit_points;
	this->_energy_points = robot._energy_points;
	this->_max_energy_points = robot._max_energy_points;
	this->_level = robot._level;
	this->_melee_attack = robot._melee_attack;
	this->_ranged_attack = robot._ranged_attack;
	this->_armor_damage = robot._armor_damage;
	this->_name = robot._name + "_copy";
	return (*this);
}

void NinjaTrap::no_power(void) const
{
	std::cout << red << "Oh, ninja " << _name << " has lost his power, but it's temporary..." << cancel << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &target) const
{
	if (_hit_points)
	{
		std::cout << yellow << _name << " : the first priority to the ninja is to win without fighting! Attack ClapTrap!\n";
		target.takeDamage(5);
	}
	else
		no_power();
}

void NinjaTrap::ninjaShoebox(FragTrap &target) const
{
	if (_hit_points)
	{
		std::cout << yellow << _name << " : stealth attack on FragTrap!\n";
		target.takeDamage(42);
	}
	else
		no_power();
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) const
{
	if (_hit_points)
	{
		target.challengeNewcomer();
		std::cout << yellow << _name << " : leave your riddles to others! *katana whistling over ScavTrap's head*\n";
		target.takeDamage(60);
	}
	else
		no_power();
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target) const
{
	if (_hit_points)
	{
		std::cout << yellow << _name << " : only a ninja can stop ninja! Finally, a worthy opponent...\n";
		target.takeDamage(30);
	}
	else
		no_power();
}

void NinjaTrap::attack(const std::string &type, const std::string &target) const
{
	if (_hit_points)
	{
		std::cout << yellow << "Ninja " << _name << " attacks " << target << " at " << type << ", causing " << \
		(!target.compare("range") ? _ranged_attack : _melee_attack) << " points of damage!";
	}
	else
		no_power();
	std::cout << cancel << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target) const
{
	attack("range", target);
}

void NinjaTrap::meleeAttack(std::string const &target) const
{
	attack("melee", target);
}