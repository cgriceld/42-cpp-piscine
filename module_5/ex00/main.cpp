#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bur("Tom", 50);
		Bureaucrat bur1("Jerry", 5);
		Bureaucrat copy(bur);
		std::cout << copy;
		std::cout << "------------------\n";

		copy = bur1;
		std::cout << bur << bur1 << copy;
		std::cout << "------------------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat high("Tom", -5);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat low("Tom", 200);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat bur("Tom", 1);
	Bureaucrat bur1("Jerry", 150);
	std::cout << bur << bur1;
	try
	{
		bur.incr();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		bur1.decr();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	bur.decr();
	bur1.incr();
	std::cout << bur << bur1;
	
	return (0);
}