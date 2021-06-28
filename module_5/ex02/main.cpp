#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		ShrubberyCreationForm home("home");
		Bureaucrat bur("Tom", 130);
		std::cout << home << bur;
		bur.signForm(home);
		std::cout << home;
		bur.executeForm(home);
		Bureaucrat bur1("Jerry", 150);
		bur1.executeForm(home);
		std::cout << "------------------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}