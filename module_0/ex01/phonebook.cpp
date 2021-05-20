#include "phonebook.hpp"
#include <iostream>

int Phonebook::geti(void) const
{
	return (this->_i);
}

void Phonebook::add(void)
{
	std::cout << "First name : ";
	std::getline(std::cin, this->_firstname);
	std::cout << "Last name : ";
	std::getline(std::cin, this->_lastname);
	std::cout << "Nickname : ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Login : ";
	std::getline(std::cin, this->_login);
	std::cout << "Postal address : ";
	std::getline(std::cin, this->_address);
	std::cout << "Email : ";
	std::getline(std::cin, this->_email);
	std::cout << "Phone : ";
	std::getline(std::cin, this->_phone);
	std::cout << "Birthday : ";
	std::getline(std::cin, this->_birthday);
	std::cout << "Favorite meal : ";
	std::getline(std::cin, this->_meal);
	std::cout << "Underwear color : ";
	std::getline(std::cin, this->_underwear);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, this->_secret);
}

void Phonebook::print_brief(void)
{

}