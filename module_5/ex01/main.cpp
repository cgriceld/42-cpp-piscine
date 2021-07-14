#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Form bill("bill", 10, 5);
		Form copy(bill);
		Form invoice("invoice", 50, 45);
		std::cout << copy;
		std::cout << "------------------\n";

		copy = invoice;
		std::cout << bill << invoice << copy;
		std::cout << "------------------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		Form high("bill", 5, -11);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		Form low("bill", 151, 40);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		std::cout << "------------------\n";
		Form bill("bill", 10, 5);
		Form invoice("invoice", 50, 45);
		Bureaucrat bur("Tom", 60);
		Bureaucrat bur1("Jerry", 5);
		std::cout << bill << invoice << bur << bur1;
		std::cout << "------------------\n";
		bur1.signForm(bill);
		bur1.signForm(bill);
		bur.signForm(invoice);
		bur1.signForm(invoice);
		std::cout << "------------------\n";
		std::cout << bill << invoice;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}