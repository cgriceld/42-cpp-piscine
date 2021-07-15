#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(0));

	try
	{
		Intern Cole;
		Intern Zena(Cole);
		Form *shr = Cole.makeForm("shrubbery creation", "home");
		if (shr)
			std::cout << *shr;
		std::cout << "--------------------\n";
		Form *rob = Zena.makeForm("robotomy request", "plant");
		if (rob)
			std::cout << *rob;
		std::cout << "--------------------\n";
		Form *wrong = Zena.makeForm("no form", "no target");
		static_cast<void>(wrong);
		std::cout << "--------------------\n";
		Form *pard = Cole.makeForm("presidential pardon", "Neil");
		if (pard)
			std::cout << *pard;
		std::cout << "--------------------\n";
		Bureaucrat bur("Kate", 1);
		bur.signForm(*pard);
		bur.executeForm(*pard);
		delete shr;
		delete rob;
		delete pard;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}

	return (0);
}