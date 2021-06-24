#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <cstddef>
#include <iostream>

class Squad : public ISquad
{
public:
	Squad();
	Squad(const Squad &copy);
	virtual ~Squad();

	Squad &operator = (const Squad &copy);

	int getCount(void) const;
	ISpaceMarine *getUnit(int i) const;
	int push(ISpaceMarine *elem);

private:
	ISpaceMarine **_squad;
	int _capacity;
	int _count;

	void free_squad(void);
	bool is_in(ISpaceMarine *elem) const;
	void squad_error(const std::bad_alloc &e);
};

#endif