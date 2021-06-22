#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(const std::string &name, const std::string &title);
	Sorcerer(const Sorcerer &copy);
	~Sorcerer();

	Sorcerer &operator = (const Sorcerer &copy);

	std::string get_name(void) const;
	std::string get_title(void) const;
	void polymorph(Victim const &vic) const;

private:
	Sorcerer();
	void hello(void) const;

	std::string _name;
	std::string _title;
};

std::ostream &operator << (std::ostream &stream, const Sorcerer &sor);

#endif