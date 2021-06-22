#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _hit_points(100), _max_hit_points(100), \
_energy_points(50), _max_energy_points(50), _level(1), _melee_attack(20), _ranged_attack(15), \
_armor_damage(3), _name("Jack")
{
	std::cout << bold_green << "No input data..." << cancel << std::endl;
	this->set_up();
}

ScavTrap::ScavTrap(const std::string &name) : _hit_points(100), _max_hit_points(100), \
_energy_points(50), _max_energy_points(50), _level(1), _melee_attack(20), _ranged_attack(15), \
_armor_damage(3), _name(name)
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

void ScavTrap::set_up(void) const
{
	std::srand(time(0));
	std::cout << green << "Recompiling my combat code... My name is " << bold_green + _name + cancel + "." << std::endl << \
	green << "Look out everybody! Things are about to get awesome! Wheeeee!" \
	<< cancel << std::endl;
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

void ScavTrap::attack(const std::string &type, const std::string &target) const
{
	if (_hit_points)
	{
		std::cout << yellow << _name << " : You versus me! Me versus you! Either way! *performs " << type << " attack against " << \
		target << ", " << (!target.compare("range") ? _ranged_attack : _melee_attack) << " damage*" << \
		std::endl << "Is it dead? Can, can I open my eyes now?";
	}
	else
		std::cout << red << _name << ": Where'd all my bullets go? Hnngh! Empty!";
	std::cout << cancel << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target) const
{
	attack("range", target);
}

void ScavTrap::meleeAttack(std::string const &target) const
{
	attack("melee", target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (!_hit_points)
		std::cout << red << _name << " is already kind of dead inside...";
	else if (static_cast<int>(amount) <= _armor_damage)
		std::cout << yellow << _name << " didn't even flinch...";
	else
	{
		_hit_points -= (amount - _armor_damage);
		if (_hit_points > 0)
			std::cout << yellow <<  _name << " was damaged and now has " << _hit_points << "XP *looser beep*";
		else
		{
			_hit_points = 0;
			std::cout << red << _name << " is mortally damaged, needs repair...";
		}
	}
	std::cout << cancel << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == _max_hit_points)
		std::cout << yellow << _name << " is already fully functional";
	else
	{
		_hit_points = (_hit_points + static_cast<int>(amount)) >= _max_hit_points ? _max_hit_points : _hit_points + amount;
		std::cout << yellow << _name << " was repaired and now has " << _hit_points << "XP";
	}
	std::cout << cancel << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
	if (!_energy_points)
		std::cout << red << _name << " : my own life is a challenge now, no time for others *no energy*";
	else
	{
		std::string names[6] = {"Learn Java in 5 minutes", "Bite your elbow", "Pass CAPTCHA", \
		"Repeat the thirteenth labour of Hercules", "Go back in time", "Draw a perfect circle in one touch"};
		_energy_points -= 10;
		std::cout << yellow << _name << " : your challenge is..." << names[rand() % 6];
	}
	std::cout << cancel << std::endl;
}