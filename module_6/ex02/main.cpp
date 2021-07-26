#include <iostream>
#include <ctime>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void)
{
	int i = std::rand() % 3;
	Base *tmp;
	try
	{
		if (!i)
		{
			std::cout << "generates A\n";
			tmp = new A();
			return (tmp);
		}
		if (i == 1)
		{
			std::cout << "generates B\n";
			tmp = new B();
			return (tmp);
		}
		else
		{
			std::cout << "generates C\n";
			tmp = new C();
			return (tmp);
		}
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << ", returns null\n";
		return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base &p)
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
	}
	catch (const std::bad_cast &e) {}

	try
	{
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "B" << std::endl;
	}
	catch (const std::bad_cast &e) {}

	try
	{
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "C" << std::endl;
	}
	catch (const std::bad_cast &e) {}
}

int main(void)
{
	srand(time(0));
	for (int i = 0; i < 6; i++)
	{
		std::cout << "------------\n";
		Base *ptr = generate();
		if (!ptr)
			continue;
		std::cout << "by pointer : ";
		identify(ptr);
		std::cout << "by reference : ";
		identify(*ptr);
		delete ptr;
	}
	return (0);
}