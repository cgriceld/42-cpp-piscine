#include "phonebook.hpp"
#include <iostream>
#include <cctype>

static int check_index(std::string index)
{
	if (index.length() != 1)
		return (-1);
	if (!std::isdigit(index[0]))
		return (-1);
	return (index[0] == '9' ? -1 : std::stoi(index));
}

int main(void)
{
	class Phonebook book;
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
			{
				book.seti();
				book.get_contact(book.geti() - 1)->add();
			}
		}
		else if (!command.compare("SEARCH"))
		{
			if (!book.geti())
				std::cout << "Phonebook is empty, no search is available" << std::endl;
			else
			{
				book.search();
				std::cout << "Choose one of above indexes: ";
				std::getline(std::cin, command);
				int i = check_index(command);
				if (i < 0)
					std::cout << "Wrong index" << std::endl;
				else
					book.get_contact(i)->print_full();
			}
		}
		else if (!command.compare("EXIT"))
			break;
		else
			std::cout << "Ambiguous command, try again" << std::endl;
	}
	return (0);
}