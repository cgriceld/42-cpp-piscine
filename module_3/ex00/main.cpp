#include "FragTrap.hpp"

int main(void)
{
	FragTrap claptrap("Claptrap");
	std::cout << "-------------------\n";
	FragTrap dflt;
	std::cout << "-------------------\n";
	FragTrap tallneck(dflt);
	std::cout << "-------------------\n";

	dflt.beRepaired(42);
	std::cout << "-------------------\n";
	dflt.meleeAttack("Zombie");
	std::cout << "-------------------\n";
	dflt.rangedAttack("Android");
	std::cout << "-------------------\n";
	dflt.takeDamage(200);
	std::cout << "-------------------\n";
	dflt.beRepaired(21);
	std::cout << "-------------------\n";
	dflt.takeDamage(50);
	std::cout << "-------------------\n";
	dflt.beRepaired(300);
	std::cout << "-------------------\n";
	dflt.vaulthunter_dot_exe("Ethan");
	std::cout << "-------------------\n";
	dflt.vaulthunter_dot_exe("Ethan");
	std::cout << "-------------------\n";
	dflt.vaulthunter_dot_exe("Ethan");
	std::cout << "-------------------\n";
	dflt.vaulthunter_dot_exe("Ethan");
	std::cout << "-------------------\n";
	dflt.vaulthunter_dot_exe("Ethan");
	std::cout << "-------------------\n";
	dflt.takeDamage(70);
	std::cout << "-------------------\n";
	dflt.beRepaired(40);
	std::cout << "-------------------\n";
	dflt.takeDamage(17);
	std::cout << "-------------------\n";
	dflt.takeDamage(63);
	std::cout << "-------------------\n";
	dflt.takeDamage(4);
	std::cout << "-------------------\n";
	dflt.takeDamage(60);
	std::cout << "-------------------\n";
	dflt.meleeAttack("Zombie");
	std::cout << "-------------------\n";

	return (0);
}