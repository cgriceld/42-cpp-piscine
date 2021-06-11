#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100, 100, 50, 50, 1, 20, 15, 3, "Jack", SCAV)
{
	std::cout << bold_green << "No input data..." << cancel << std::endl;
	this->set_up();
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(100, 100, 50, 50, 1, 20, 15, 3, name, SCAV)
{
	std::cout << bold_green << "Input data processing..." << cancel << std::endl;
	this->set_up();
};

ScavTrap::ScavTrap(const ScavTrap &robot)
{
	std::cout << bold_green << "Copying input data..." << cancel << std::endl;
	*this = robot;
	this->set_up();
}

ScavTrap::~ScavTrap()
{
	std::cout << yellow <<  _name << " : I'll stop talking when I'm dead!" << cancel << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &robot)
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

void ScavTrap::challengeNewcomer()
{
	if (!_energy_points)
		std::cout << red << _name << " : my own life is a challenge now, no time for others *no energy*";
	else
	{
		std::string names[6] = {"Learn Java in 5 minutes", "Bite your elbow", "Pass CAPTCHA", \
		"Repeat the thirteenth labour of Hercules", "Go back in time", "Walk backwards for an hour"};
		_energy_points -= 10;
		std::cout << yellow << _name << " : your challenge is..." << names[rand() % 6];
	}
	std::cout << cancel << std::endl;
}