#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

int Phonebook::geti(void) const
{
	return (this->_i);
}

void Phonebook::seti(void)
{
	this->_i++;
}

Contact *Phonebook::get_contact(int _i)
{
	return (&(this->_info[_i]));
}

void Phonebook::search(void) const
{
	for (int i = 0; i < this->_i; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->_info[i].print_short();
		std::cout << std::endl;
	}
}