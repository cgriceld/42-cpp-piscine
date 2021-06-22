#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(const std::string &name);
	Peon(const Peon &copy);
	virtual ~Peon();

	Peon &operator = (const Peon &copy);

	void getPolymorphed(void) const;

protected:
	Peon();
	void hello(void) const;
};

#endif