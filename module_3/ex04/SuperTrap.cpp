#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(100, 100, 120, 120, 1, 60, 20, 5, "Lisa")
{
	// set_hp(100);
	// set_maxhp(100);
	// set_energy(120);
	// set_maxenergy(120);
	// set_melee(60);
	// set_range(20);
	// set_armor(5);
	// set_name("Lisa");
	std::cout << bold_green << "Default SuperTrap constructor called!\n" << cancel;
	set_up();
}

SuperTrap::SuperTrap(const std::string &name) : ClapTrap(100, 100, 120, 120, 1, 60, 20, 5, name)
{
	// set_hp(100);
	// set_maxhp(100);
	// set_energy(120);
	// set_maxenergy(120);
	// set_melee(60);
	// set_range(20);
	// set_armor(5);
	// set_name(name);
	std::cout << bold_green << "SuperTrap constructor with name configuration -- done!\n" << cancel;
	set_up();
}

SuperTrap::SuperTrap(const SuperTrap &robot)
{
	std::cout << bold_green << "SuperTrap copying conrtuctor call..." << cancel << std::endl;
	*this = robot;
	set_up();
}

SuperTrap::~SuperTrap()
{
	std::cout << yellow <<  _name << " : bye-bye!" << cancel << std::endl;
}

void SuperTrap::set_up(void) const
{
	std::cout << bold_green << "Hello from " << _name << "!" << cancel << std::endl;
}

SuperTrap &SuperTrap::operator = (const SuperTrap &robot)
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

void SuperTrap::rangedAttack(std::string const &target) const
{
	FragTrap::rangedAttack(target);
}
void SuperTrap::meleeAttack(std::string const &target) const
{
	NinjaTrap::meleeAttack(target);
}