#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
public:
	Contact();
	~Contact();

	void add(void);
	void print_short(void) const;
	void print_full(void) const;

private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _login;
	std::string _address;
	std::string _email;
	std::string _phone;
	std::string _birthday;
	std::string _meal;
	std::string _underwear;
	std::string _secret;
};

#endif