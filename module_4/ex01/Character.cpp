#include "Character.hpp"

Character::Character() {};

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(NULL) {};

Character::Character(const Character &copy) : _name(copy._name), _ap(copy._ap), _weapon(copy._weapon) {};

Character::~Character() {};

Character &Character::operator = (const Character &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_ap = copy._ap;
		_weapon = copy._weapon;
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (_name);
}

int Character::get_ap(void) const
{
	return (_ap);
}

AWeapon *Character::get_weapon(void) const
{
	return (_weapon);
}

void Character::equip(AWeapon *wep)
{
	_weapon = wep;
}

void Character::recoverAP(void)
{
	_ap += 10;
	if (_ap > 40)
		_ap = 40;
}

void Character::attack(Enemy *en)
{
	if (!_weapon || _ap < _weapon->getAPCost() || !en)
		return;
	std::cout << _name << " attacks " << en->getType() << " with a " << _weapon->getName() << std::endl;
	_weapon->attack();
	_ap -= _weapon->getAPCost();
	en->takeDamage(_weapon->getAPCost());
	if (!en->getHP())
		delete en;
}

std::ostream &operator << (std::ostream &stream, const Character &ch)
{
	stream << ch.getName() << " has " << ch.get_ap() << " AP and ";
	if (!ch.get_weapon())
		stream << "is unarmed";
	else
		stream << "wields a " << ch.get_weapon()->getName();
	std::cout << std::endl;
	return (stream);
}