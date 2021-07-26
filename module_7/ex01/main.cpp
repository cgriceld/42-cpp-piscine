#include "iter.hpp"
#include <iostream>
#include <string>

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

template <typename T>
void func(const T &a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	std::cout << "INT\n";
	int i[] = {4, -7, 0, 22};
	iter(i, 4, &func);
	std::cout << "-----------\n";

	std::cout << "FLOAT\n";
	float f[] = {4.6f, -7.77f, .0f, 22.f, 9.8f};
	iter(f, 5, &func);
	std::cout << "-----------\n";

	std::cout << "DOUBLE\n";
	double d[] = {1.22, -3.55, 0.76};
	iter(d, 3, &func);
	std::cout << "-----------\n";

	std::cout << "CHAR\n";
	char c[] = {'k', 'L', ';'};
	iter(c, 3, &func);
	std::cout << "-----------\n";

	std::cout << "STRING\n";
	std::string s[] = {"school", "21"};
	iter(s, 2, &func);
	std::cout << "-----------\n";

	std::cout << "CLASS\n";
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);

	return (0);
}