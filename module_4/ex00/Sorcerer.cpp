#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {};

Sorcerer::Sorcerer(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	hello();
}

Sorcerer::Sorcerer(const Sorcerer &copy) : _name(copy._name), _title(copy._title)
{
	hello();
};

Sorcerer &Sorcerer::operator = (const Sorcerer &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_title = copy._title;
	}
	return (*this);
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!\n";
}

void Sorcerer::hello(void) const
{
	std::cout << _name << ", " << _title << ", is born!\n";
}

std::string Sorcerer::get_name(void) const
{
	return (_name);
}

std::string Sorcerer::get_title(void) const
{
	return (_title);
}

std::ostream &operator << (std::ostream &stream, const Sorcerer &sor)
{
	stream << "I am " << sor.get_name() << ", " << sor.get_title() << ", and I like ponies!\n";
	return (stream);
}

void Sorcerer::polymorph(Victim const &vic) const
{
	vic.getPolymorphed();
}