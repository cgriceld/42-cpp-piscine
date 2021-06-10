#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	std::cout << "-------------\n";
	Fixed const b( 10 );
	std::cout << "-------------\n";
	Fixed const c( 42.42f );
	std::cout << "-------------\n";
	Fixed const d( b );
	std::cout << "-------------\n";

	a = Fixed( 1234.4321f );
	std::cout << "-------------\n";

	std::cout << "a is " << a << std::endl;
	std::cout << "-------------\n";
	std::cout << "b is " << b << std::endl;
	std::cout << "-------------\n";
	std::cout << "c is " << c << std::endl;
	std::cout << "-------------\n";
	std::cout << "d is " << d << std::endl;
	std::cout << "-------------\n";

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "-------------\n";
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "-------------\n";
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "-------------\n";
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "-------------\n";

	return (0);
}