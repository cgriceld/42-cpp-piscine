#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>

class Phonebook
{
public:

	Phonebook() : _i(0) {};
	~Phonebook();
	int geti(void) const;

	void add(void);
	void print_brief(void);

private:

	int _i;
	struct Contact
	{
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
};

#endif