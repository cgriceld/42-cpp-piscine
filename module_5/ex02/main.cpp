#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(0));

	try
	{
		ShrubberyCreationForm home("home");
		RobotomyRequestForm laptop("plant");
		PresidentialPardonForm Bob("Bob");
		PresidentialPardonForm Lisa("Lisa");
		ShrubberyCreationForm dacha("dacha");
		Bureaucrat bur("Tom", 40);
		Bureaucrat bur1("Kate", 150);
		Bureaucrat bur2("Jerry", 5);
		std::cout << home << laptop << Bob << Lisa << dacha << bur << bur1 << bur2;
		std::cout << "------------------\n";
		bur.executeForm(home);
		bur.signForm(home);
		std::cout << home;
		bur2.executeForm(home);
		bur1.executeForm(home);
		std::cout << "------------------\n";
		bur2.signForm(laptop);
		for (int i = 0; i < 5; i++)
			bur.executeForm(laptop);
		std::cout << "------------------\n";
		Bureaucrat burs[] = {bur, bur1, bur2};
		for (int i = 0; i < 3; i++)
			burs[i].signForm(Bob);
		for (int i = 0; i < 3; i++)
			burs[i].executeForm(Bob);
		std::cout << "------------------\n";
		bur2.signForm(Lisa);
		bur2.executeForm(Lisa);
		bur.signForm(dacha);
		bur.executeForm(dacha);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}