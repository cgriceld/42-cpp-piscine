#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
	Brain();
	~Brain();

	int get_cells(void) const;
	void set_cells(int i);
	std::string identify(void) const;

private:
	int _cells;
};

#endif