#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"
#include <iostream>

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	RadScorpion(const RadScorpion &copy);
	virtual ~RadScorpion();

	RadScorpion &operator = (const RadScorpion &copy);

private:
	void hello(void) const;
};

#endif