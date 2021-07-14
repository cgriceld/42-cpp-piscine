#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	srand(time(0));

	try
	{
		ShrubberyCreationForm home("home");
		RobotomyRequestForm laptop("laptop");
		Bureaucrat bur("Tom", 130);
		Bureaucrat bur1("Kate", 150);
		Bureaucrat bur2("Jerry", 20);
		std::cout << home << laptop << bur << bur1 << bur2;
		std::cout << "------------------\n";
		bur.executeForm(home);
		bur.signForm(home);
		std::cout << home;
		bur2.executeForm(home);
		bur1.executeForm(home);
		std::cout << "------------------\n";
		// bur2.signForm(laptop);
		// for (int i = 0; i < 5; i++)
		// 	bur2.executeForm(laptop);
		// bur.executeForm(laptop);
		// std::cout << "------------------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}