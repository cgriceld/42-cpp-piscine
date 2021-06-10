#include "FragTrap.hpp"

FragTrap::FragTrap() : _hit_points(100), _max_hit_points(100), \
_energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), \
_armor_damage(5), _name("Wall-E")
{
	std::cout << bold_green << "No input data..." << cancel << std::endl;
	this->set_up();
}

FragTrap::FragTrap(const std::string &name) : _hit_points(100), _max_hit_points(100), \
_energy_points(100), _max_energy_points(100), _level(1), _melee_attack(30), _ranged_attack(20), \
_armor_damage(5), _name(name)
{
	std::cout << bold_green << "Input data processing..." << cancel << std::endl;
	this->set_up();
}

FragTrap::FragTrap(const FragTrap &robot)
{
	std::cout << bold_green << "Copying input data..." << cancel << std::endl;
	*this = robot;
	this->set_up();
}

FragTrap::~FragTrap()
{
	std::cout << yellow <<  _name << " system shut down... *sad beep*" << cancel << std::endl;
}

void FragTrap::set_up(void) const
{
	this->intro();
	std::srand(time(0));
}

void FragTrap::intro(void) const
{
	std::cout << green << "Booting sequence complete. Beep-Beep! I'm " << bold_green + _name + cancel + "." << std::endl << \
	green << "Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!" \
	<< cancel << std::endl;
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
	return (*this);
}

void FragTrap::attack(std::string &type, const std::string &target) const
{
	if (_hit_points)
	{
		std::cout << yellow << "FR4G-TP " << _name << " attacks " << target << " at " << type << ", causing " << \
		(!target.compare("range") ? _ranged_attack : _melee_attack) << " points of damage! *furious beep*";
	}
	else
		std::cout << red << "FR4G-TP " << _name << " is powerless because it's damaged, needs repair... *broken beep*";
	std::cout << cancel << std::endl;
}

void FragTrap::rangedAttack(std::string const &target) const
{
	std::string type("range");
	attack(type, target);
}

void FragTrap::meleeAttack(std::string const &target) const
{
	std::string type("melee");
	attack(type, target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	int tmp;

	if (!_hit_points)
		std::cout << red << "FR4G-TP " << _name << " is already mortally damaged, needs repair... *broken beep*";
	else if (amount <= _armor_damage)
		std::cout << yellow << "FR4G-TP " << _name << " didn't even flinch... *brave beep*";
	else
	{
		tmp = amount - _armor_damage;
		if (_hit_points > tmp)
		{
			_hit_points -= tmp;
			std::cout << yellow << "FR4G-TP " << _name << " was damaged and now has " << _hit_points << "XP *looser beep*";
		}
		else
		{
			_hit_points = 0;
			std::cout << red << "FR4G-TP " << _name << " is mortally damaged, needs repair... *broken beep*";
		}
	}
	std::cout << cancel << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == _max_hit_points)
		std::cout << yellow << "FR4G-TP " << _name << " is already fully functional *cheery beep*";
	else
	{
		_hit_points = amount >= _max_hit_points ? _max_hit_points : _hit_points + amount;
		std::cout << yellow << "FR4G-TP " << _name << " was repaired and now has " << _hit_points << "XP *thankful beep*";
	}
	std::cout << cancel << std::endl;
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