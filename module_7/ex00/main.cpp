#include "whatever.hpp"
#include <iostream>
#include <string>

class Awesome
{
	public:
			Awesome(int n) : _n(n) {}
		bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
		bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }

		int getn(void) const {return _n;};

	private:
		int _n;
};

std::ostream &operator<<(std::ostream &rs, Awesome const &rhs)
{
	std::cout << rhs.getn();
	return (rs);
}

template <typename T>
void test(T &a, T &b)
{
	std::cout << "before swap : a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap : a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "-------------\n";
}

int main(void)
{
	std::cout << "INT\n";
	int ai = 2;
	int bi = 3;
	test(ai, bi);

	std::cout << "FLOAT\n";
	float af = 2.4f;
	float bf = 55.f;
	test(af, bf);

	std::cout << "DOUBLE\n";
	double ad = 322.5;
	double bd = 322.78;
	test(ad, bd);

	std::cout << "CHAR\n";
	char ac = 'k';
	char bc = 'M';
	test(ac, bc);

	std::cout << "STRING\n";
	std::string as = "chaine1";
	std::string bs = "chaine2";
	test(as, bs);

	std::cout << "CLASS\n";
	Awesome cl1(42);
	Awesome cl2(21);
	test(cl1, cl2);

	return (0);
}