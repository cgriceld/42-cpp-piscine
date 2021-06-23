#ifndef CLICKER_HPP
# define CLICKER_HPP

#include "Enemy.hpp"
#include <iostream>

class Clicker : public Enemy
{
public:
	Clicker();
	Clicker(const Clicker &copy);
	virtual ~Clicker();

	Clicker &operator = (const Clicker &copy);

	void takeDamage(int amount);

private:
	void hello(void) const;
};

#endif