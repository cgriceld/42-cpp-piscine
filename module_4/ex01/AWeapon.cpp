#include "AWeapon.hpp"

AWeapon::AWeapon() {};

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage) {};

AWeapon::AWeapon(const AWeapon &copy) : _name(copy._name), _apcost(copy._apcost), _damage(copy._damage) {};

AWeapon::~AWeapon() {};

AWeapon &AWeapon::operator = (const AWeapon &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_apcost = copy._apcost;
		_damage = copy._damage;
	}
	return (*this);
}

std::string const &AWeapon::getName(void) const
{
	return (_name);
}

int AWeapon::getAPCost(void) const
{
	return (_apcost);
}

int AWeapon::getDamage(void) const
{
	return (_damage);
}