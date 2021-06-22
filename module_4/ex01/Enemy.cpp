#include "Enemy.hpp"

Enemy::Enemy() {};

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type) {};

Enemy::Enemy(const Enemy &copy) : _hp(copy._hp), _type(copy._type) {};

Enemy::~Enemy() {};

Enemy &Enemy::operator = (const Enemy &copy)
{
	if (this != &copy)
	{
		_hp = copy._hp;
		_type = copy._type;
	}
	return (*this);
}

std::string const &Enemy::getType(void) const
{
	return (_type);
}

int Enemy::getHP(void) const
{
	return (_hp);
}

void Enemy::takeDamage(int amount)
{
	if (amount <= 0 || !_hp)
		return;
	_hp -= amount;
	if (_hp < 0)
		_hp = 0;
}