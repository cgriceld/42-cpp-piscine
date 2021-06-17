#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(50), _max_hit_points(50), \
_energy_points(100), _max_energy_points(100), _level(1), _melee_attack(0), _ranged_attack(0), \
_armor_damage(5), _name("Tom")
{
	std::cout << bold_green << "Default ClapTrap loading..." << cancel << std::endl;
	this->set_up();
}

ClapTrap::ClapTrap(const unsigned int &hit_points, const unsigned int &max_hit_points, \
	const unsigned int &energy_points, const unsigned int &max_energy_points, \
	const unsigned int &level, const unsigned int &melee_attack, \
	const unsigned int &ranged_attack, const unsigned int &armor_damage, \
	const std::string &name) : _hit_points(hit_points), _max_hit_points(max_hit_points), \
_energy_points(energy_points), _max_energy_points(max_energy_points), _level(level), _melee_attack(melee_attack), \
_ranged_attack(ranged_attack), _armor_damage(armor_damage), _name(name)
{
	std::cout << bold_green << "Input data processing...\n" << cancel;
};

ClapTrap::ClapTrap(const ClapTrap &robot)
{
	std::cout << bold_green << "Copying input data..." << cancel << std::endl;
	*this = robot;
	this->set_up();
}

ClapTrap::~ClapTrap()
{
	std::cout << yellow << "ClapTrap that maintains " << _name << " was deleted." << cancel << std::endl;
}

void ClapTrap::set_up(void) const
{
	std::cout << green << "Hi there! I'm " << bold_green + _name + cancel + "." << std::endl << \
	green << "I can only launch other robots.\n" << cancel;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &robot)
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

void ClapTrap::takeDamage(unsigned int amount)
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

void ClapTrap::beRepaired(unsigned int amount)
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