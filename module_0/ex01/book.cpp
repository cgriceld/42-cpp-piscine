#include "phonebook.hpp"
#include <iostream>

int main(void)
{
	class Phonebook book[8];
	std::string command;

	std::cout << "ADD: to add contact, SEARCH: to search contacts, EXIT: to exit" << std::endl;
	while (1)
	{
		std::cout << "Type command : ";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			if (book.geti() == 8)
				std::cout << "Sorry, phonebook is already full" << std::endl;
			else
				book.add();
		}
		else if (!command.compare("SEARCH"))
		{

		}
		else
			std::cout << "Ambiguous command, try again" << std::endl;
	}

	return (0);
}