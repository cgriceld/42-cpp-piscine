#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Tom"), _type("CLAP")
{
	std::cout << bold_green << "Default ClapTrap loading..." << cancel << std::endl;
	this->set_up();
}

ClapTrap::ClapTrap(const unsigned int &hit_points, const unsigned int &max_hit_points, \
	const unsigned int &energy_points, const unsigned int &max_energy_points, \
	const unsigned int &level, const unsigned int &melee_attack, \
	const unsigned int &ranged_attack, const unsigned int &armor_damage, \
	const std::string &name, const std::string &type) : _hit_points(hit_points), _max_hit_points(max_hit_points), \
_energy_points(energy_points), _max_energy_points(max_energy_points), _level(level), _melee_attack(melee_attack), \
_ranged_attack(ranged_attack), _armor_damage(armor_damage), _name(name), _type(type)
{
	std::cout << bold_green << "Input data processing...\n" << cancel << \
	green << "ClapTrap adjusting settings depending on chosen type...wait..." << std::endl;
	this->set_up();
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
	this->intro();
	std::srand(time(0));
}

void ClapTrap::intro(void) const
{
	if (!_type.compare("SCAV"))
	{
		std::cout << green << "Recompiling my combat code... My name is " << bold_green + _name + cancel + "." << std::endl << \
		green << "Look out everybody! Things are about to get awesome! Wheeeee!";
	}
	else if (!_type.compare("FRAG"))
	{
		std::cout << green << "Booting sequence complete. Beep-Beep! I'm " << bold_green + _name + cancel + "." << std::endl << \
		green << "Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!";
	}
	else if (!_type.compare("NINJA"))
		std::cout << green << "Konnichiwa! I'm " << bold_green + _name + cancel + ".";
	else
	{
		std::cout << green << "Hi there! I'm " << bold_green + _name + cancel + "." << std::endl << \
		green << "I can only launch others.";
	}
	std::cout << cancel << std::endl;
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
	this->_type = robot._type;
	return (*this);
}

void ClapTrap::attack(std::string &type, const std::string &target) const
{
	if (!_type.compare("FRAG"))
	{
		if (_hit_points)
		{
			std::cout << yellow << "FR4G-TP " << _name << " attacks " << target << " at " << type << ", causing " << \
			(!target.compare("range") ? _ranged_attack : _melee_attack) << " points of damage! *furious beep*";
		}
		else
			std::cout << red << "FR4G-TP " << _name << " is powerless because it's damaged, needs repair... *broken beep*";
	}
	else if (!_type.compare("SCAV"))
	{
		if (_hit_points)
		{
			std::cout << yellow << _name << " : You versus me! Me versus you! Either way! *performs " << type << " attack against " << \
			target << ", " << (!target.compare("range") ? _ranged_attack : _melee_attack) << " damage*" << \
			std::endl << "Is it dead? Can, can I open my eyes now?";
		}
		else
			std::cout << red << _name << ": Where'd all my bullets go? Hnngh! Empty!";
	}
	else if (!_type.compare("CLAP"))
		std::cout << yellow << "ClapTraps can't attack!";
	else
	{
		if (_hit_points)
		{
			std::cout << yellow << "Ninja" << _name << " attacks " << target << " at " << type << " with " << \
			(!target.compare("range") ? _ranged_attack : _melee_attack) << " damage! Or not? It's so dark in here, I didn't quite notice!";
		}
		else
			std::cout << red << "Oh, ninja " << _name << " has lost his power, but it's temporary...";
	}
	std::cout << cancel << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target) const
{
	std::string type("range");
	attack(type, target);
}

void ClapTrap::meleeAttack(std::string const &target) const
{
	std::string type("melee");
	attack(type, target);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int tmp;

	if (!_type.compare("SCAV"))
	{
		if (!_hit_points)
			std::cout << red << _name << " : you know, I'm already kind of dead inside...";
		else if (amount <= _armor_damage)
			std::cout << yellow << _name << " : I am so impressed with myself! *no damage*";
		else
		{
			tmp = amount - _armor_damage;
			if (_hit_points > tmp)
			{
				_hit_points -= tmp;
				std::cout << yellow <<  _name << " : Ow hohoho, that hurts! Yipes! *current XP: " << _hit_points << "*";
			}
			else
			{
				_hit_points = 0;
				std::cout << red << _name << " : Aaaughhh... Why do I even feel pain?! *mortally damaged*";
			}
		}
	}
	else if (!_type.compare("FRAG"))
	{
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
	}
	else if (!_type.compare("CLAP"))
		std::cout << yellow << "ClapTraps can't take damage!";
	else
	{
		if (!_hit_points)
			std::cout << red << "Ninja " << _name << " is already mortally wounded";
		else
		{
			if (_hit_points - amount)
			{
				_hit_points -= amount;
				std::cout << yellow << "Ninja " << _name << " was wounded and now has " << _hit_points;
			}
			else
			{
				_hit_points = 0;
				std::cout << red << "Ninja " << _name << " is mortally wounded";
			}
		}
	}
	std::cout << cancel << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_type.compare("FRAG"))
	{
		if (_hit_points == _max_hit_points)
			std::cout << yellow << "FR4G-TP " << _name << " is already fully functional *cheery beep*";
		else
		{
			_hit_points = amount >= _max_hit_points ? _max_hit_points : _hit_points + amount;
			std::cout << yellow << "FR4G-TP " << _name << " was repaired and now has " << _hit_points << "XP *thankful beep*";
		}
	}
	else if (!_type.compare("SCAV"))
	{
		if (_hit_points == _max_hit_points)
			std::cout << yellow << _name << " : Better lucky than good! *XP already full*";
		else
		{
			_hit_points = amount >= _max_hit_points ? _max_hit_points : _hit_points + amount;
			std::cout << yellow <<  _name << " : Health over here! *current XP: " << _hit_points << "*";
		}
	}
	else if (!_type.compare("CLAP"))
		std::cout << yellow << "ClapTraps can't be repaired!";
	else
	{
		if (_hit_points == _max_hit_points)
			std::cout << yellow << _name << " : my XP is already full";
		else
		{
			_hit_points = amount >= _max_hit_points ? _max_hit_points : _hit_points + amount;
			std::cout << yellow <<  _name << " : health restored, current XP: " << _hit_points;
		}
	}
	std::cout << cancel << std::endl;
}