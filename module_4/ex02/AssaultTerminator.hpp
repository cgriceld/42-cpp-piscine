#ifndef ASAULTTERMINATOR_HPP
# define ASAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &copy);
	virtual ~AssaultTerminator();

	AssaultTerminator &operator = (const AssaultTerminator &copy);

	ISpaceMarine *clone(void) const;
	void battleCry(void) const;
	void rangedAttack(void) const;
	void meleeAttack(void) const;

private:
	void hello(void) const;
};

#endif