#include "Victim.hpp"

Victim::Victim() {};

Victim::Victim(const std::string &name) : _name(name)
{
	hello();
}

Victim::Victim(const Victim &copy) : _name(copy._name)
{
	hello();
};

Victim &Victim::operator = (const Victim &copy)
{
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!\n";
}

void Victim::hello(void) const
{
	std::cout << "Some random victim called " << _name << " just appeared!\n";
}

std::string Victim::get_name(void) const
{
	return (_name);
}

std::ostream &operator << (std::ostream &stream, const Victim &vic)
{
	stream << "I'm " << vic.get_name() << " and I like otters!\n";
	return (stream);
}

void Victim::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a cute little sheep!\n";
}