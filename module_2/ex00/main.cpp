#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	std::cout << "-------------\n";
	Fixed b( a );
	std::cout << "-------------\n";
	Fixed c;
	std::cout << "-------------\n";

	c = b;
	std::cout << "-------------\n";
	a = b = c;
	std::cout << "-------------\n";

	std::cout << a.getRawBits() << std::endl;
	std::cout << "-------------\n";
	std::cout << b.getRawBits() << std::endl;
	std::cout << "-------------\n";
	std::cout << c.getRawBits() << std::endl;
	std::cout << "-------------\n";

	return (0);
}