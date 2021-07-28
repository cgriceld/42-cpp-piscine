#include "Array.hpp"
#include <string>

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	Awesome (int n) : _n(n) {};
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }


int main(void)
{
	std::cout << "EMPTY ARRAY\n";
	Array<int> empty;
	std::cout << empty;
	std::cout << "------------\n";

	std::cout << "FILL ARRAY & EXCEPTION\n";
	Array<int> a(3);
	std::cout << a;
	a[2] = 4;
	a[0] = 1;
	std::cout << a;

	try
	{
		std::cout << a[12];
	}
	catch(const std::exception& e)
	{
		std::cerr << "array index out of range, try again\n";
	}
	std::cout << "------------\n";

	std::cout << "ARRAY COPY\n";
	Array<int> copy(a);
	std::cout << copy;
	std::cout << "------------\n";

	std::cout << "ARRAY ASSIGNMENT OPERATOR\n";
	empty = a;
	std::cout << empty;
	std::cout << "------------\n";

	std::cout << "STRING ARRAY\n";
	Array<std::string> c(4);
	std::cout << c;
	c[3] = "aaaa";
	c[1] = "bb!";
	std::cout << c;
	std::cout << "------------\n";

	std::cout << "CLASS ARRAY\n";
	Array<Awesome> w(4);
	std::cout << w;
	w[2] = Awesome(3);
	std::cout << w;

	return (0);
}