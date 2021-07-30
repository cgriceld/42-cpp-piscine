#include <iostream>
#include <string>

class Base
{
public:
	Base() : _a(0), _s("") {std::cout << "base constructor\n";};
	Base(int a, std::string s) : _a(a), _s(s) {std::cout << "arg base constructor\n";};
	int geta(void) const
	{
		return (_a);
	}
	std::string gets(void) const
	{
		return (_s);
	}
protected:
	int _a;
	std::string _s;

};

class A : virtual public Base
{
public:
	A() : Base(21, "A") {std::cout << "base A\n";};
	A(std::string s) : Base(21, s) {};
};

class B : virtual public Base
{
public:
	B() : Base(42, "B") {std::cout << "base B\n";};
	B(std::string s) : Base(42, s) {};
};

class C : public A, public B
{
public:
	C() {};
	C(std::string s);
};

C::C(std::string s) : Base(100, s)
{

}

int main(void)
{
	C c1;
	C c("C");

	std::cout << c1.geta() << std::endl;
	std::cout << c1.gets() << std::endl;
	std::cout << c.geta() << std::endl;
	std::cout << c.gets() << std::endl;

	return (0);
}