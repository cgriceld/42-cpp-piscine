#include "contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void Contact::print_short(void) const
{
	if (this->_firstname.length() > 10)
		std::cout << std::setw(9) << this->_firstname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->_firstname << "|";
	if (this->_lastname.length() > 10)
		std::cout << std::setw(9) << this->_lastname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->_lastname << "|";
	if (this->_nickname.length() > 10)
		std::cout << std::setw(9) << this->_nickname.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << this->_nickname;
}

void Contact::print_full(void) const
{
	std::cout << "First name : ";
	std::cout << this->_firstname << std::endl;
	std::cout << "Last name : ";
	std::cout << this->_lastname << std::endl;
	std::cout << "Nickname : ";
	std::cout << this->_nickname << std::endl;
	std::cout << "Login : ";
	std::cout << this->_login << std::endl;
	std::cout << "Postal address : ";
	std::cout << this->_address << std::endl;
	std::cout << "Email : ";
	std::cout << this->_email << std::endl;
	std::cout << "Phone : ";
	std::cout << this->_phone << std::endl;
	std::cout << "Birthday : ";
	std::cout << this->_birthday << std::endl;
	std::cout << "Favorite meal : ";
	std::cout << this->_meal << std::endl;
	std::cout << "Underwear color : ";
	std::cout << this->_underwear << std::endl;
	std::cout << "Darkest secret : ";
	std::cout << this->_secret << std::endl;
}

void Contact::add(void)
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