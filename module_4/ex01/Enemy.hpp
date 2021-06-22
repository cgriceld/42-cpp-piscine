#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy
{
public:
	Enemy(int hp, std::string const &type);
	Enemy(const Enemy &copy);
	virtual ~Enemy();

	Enemy &operator = (const Enemy &copy);

	std::string const &getType(void) const;
	int getHP(void) const;

	virtual void takeDamage(int amount);

protected:
	int _hp;
	std::string _type;

private:
	Enemy();
};

#endif