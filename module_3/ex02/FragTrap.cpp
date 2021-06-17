#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5, "Wall-E")
{
	std::cout << green << "ClapTrap adjusting settings depending on chosen type...wait..." << std::endl;
	this->set_up();
};

FragTrap::FragTrap(const std::string &name) : ClapTrap(100, 100, 100, 100, 1, 30, 20, 5, name)
{
	std::cout << green << "ClapTrap adjusting settings depending on chosen type...wait..." << std::endl;
	this->set_up();
};

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
	std::srand(time(0));
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