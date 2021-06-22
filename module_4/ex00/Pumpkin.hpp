#ifndef PUMPKIN_HPP
# define PUMPKIN_HPP

#include "Victim.hpp"

class Pumpkin : public Victim
{
public:
	Pumpkin(const std::string &name);
	Pumpkin(const Pumpkin &copy);
	virtual ~Pumpkin();

	Pumpkin &operator = (const Pumpkin &copy);

	void getPolymorphed(void) const;

private:
	Pumpkin();
	void hello(void) const;
};

#endif