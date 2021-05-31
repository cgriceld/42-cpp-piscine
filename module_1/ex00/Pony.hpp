#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include <iostream>

class Pony
{
public:
	Pony(std::string type);
	Pony(int age, std::string name, std::string type);
	~Pony();

	void introduce(void) const;

private:
	int			_age;
	std::string	_name;
	std::string	_type;
};

#endif