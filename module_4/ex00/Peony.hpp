#ifndef PEONY_HPP
# define PEONY_HPP

#include "Peon.hpp"

class Peony : public Peon
{
public:
	Peony(const std::string &name);
	Peony(const Peony &copy);
	virtual ~Peony();

	Peony &operator = (const Peony &copy);

	void getPolymorphed(void) const;

private:
	Peony();
	void hello(void) const;
};

#endif