#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, "Ishikawa", "NINJA") {};

NinjaTrap::NinjaTrap(const std::string &name) : ClapTrap(60, 60, 120, 120, 1, 60, 5, 0, name, "NINJA") {};

NinjaTrap::NinjaTrap(const NinjaTrap &robot)
{
	std::cout << bold_green << "Copying input data..." << cancel << std::endl;
	*this = robot;
	this->set_up();
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
	this->_type = robot._type;
	return (*this);
}

void NinjaTrap::no_power(void) const
{
	std::cout << red << "Oh, ninja " << _name << " has lost his power, but it's temporary...";
}

void NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	if (!_hit_points)
		std::cout << red << _name << " : you know, I'm already kind of dead inside...";
	else
		no_power();
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{

}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{

}
void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	
}