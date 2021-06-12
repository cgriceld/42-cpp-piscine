#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5, "Wall-E", "FRAG") {};

FragTrap::FragTrap(const std::string &name) : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5, name, "FRAG") {};

FragTrap::FragTrap(const FragTrap &robot)
{
	std::cout << bold_green << "Copying input data..." << cancel << std::endl;
	*this = robot;
	this->set_up();
}

FragTrap::~FragTrap()
{
	std::cout << yellow << _name << " system shut down... *sad beep*" << cancel << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &robot)
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

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (!_energy_points)
		std::cout << red << "FR4G-TP " << _name << " not have enough energy to fight... *helpless beep*";
	else
	{
		std::string names[6] = {"Torgue Fiesta", "Clap-in-the-Box", "Gun Wizard", "One-Shot Wonder", "Laser Inferno", "Pirate Ship Mode"};
		_energy_points -= 25;
		std::cout << yellow << "FR4G-TP " << _name << " successfully attacked " << target << " using " << names[rand() % 6] << " *furious beep*";
	}
	std::cout << cancel << std::endl;
}