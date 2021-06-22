#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
public:
	Victim(const std::string &name);
	Victim(const Victim &copy);
	virtual ~Victim();

	Victim &operator = (const Victim &copy);

	std::string get_name(void) const;
	virtual void getPolymorphed(void) const;

protected:
	Victim();
	virtual void hello(void) const;

	std::string _name;
};

std::ostream &operator << (std::ostream &stream, const Victim &vic);

#endif