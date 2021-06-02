#include "Brain.hpp"

#include <sstream>

Brain::Brain() : _cells(42) {};

Brain::~Brain() {};

int Brain::get_cells(void) const
{
	return (this->_cells);
};

void Brain::set_cells(int cells)
{
	this->_cells = cells;
}

std::string Brain::identify(void) const
{
	std::stringstream sstr;

	sstr << "0x" << std::uppercase << std::hex << (uintptr_t)static_cast<const void *>(this);
	return (sstr.str());
}