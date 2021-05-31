#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
public:

	Phonebook() : _i(0) {};
	~Phonebook() {};

	int		geti(void) const;
	void	search(void) const;
	void	seti(void);
	Contact	&get_contact(int _i);

private:

	int _i;
	Contact _info[8];
};

#endif