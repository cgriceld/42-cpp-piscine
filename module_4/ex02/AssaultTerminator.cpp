#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	hello();
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &copy)
{
	static_cast<void>(copy);
	hello();
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back...\n";
}

AssaultTerminator &AssaultTerminator::operator = (const AssaultTerminator &copy)
{
	static_cast<void>(copy);
	return (*this);
}

void AssaultTerminator::hello(void) const
{
	std::cout << "* teleports from space *\n";
}

ISpaceMarine *AssaultTerminator::clone(void) const
{
	try
	{
		ISpaceMarine *tmp = new AssaultTerminator(*this);
		return (tmp);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ": can't create a copy of element\n";
		return (NULL);
	}
}

void AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!\n";
}

void AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *\n";
}
