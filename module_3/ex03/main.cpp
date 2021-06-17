#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void)
{
	std::cout << "\033[1;36m PART 1 \033[0m\n\n";
	{
		FragTrap claptrap("Ben");
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
		dflt.takeDamage(200);
		std::cout << "-------------------\n";
		dflt.beRepaired(21);
		std::cout << "-------------------\n";
		dflt.takeDamage(50);
		std::cout << "-------------------\n";
		dflt.beRepaired(300);
		std::cout << "-------------------\n";
		for (int i = 0; i < 5; i++)
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
	}
	std::cout << "\n\033[1;36m PART 2 \033[0m\n\n";
	{
		ScavTrap claptrap("Ben");
		std::cout << "-------------------\n";
		ScavTrap dflt;
		std::cout << "-------------------\n";
		ScavTrap tallneck(dflt);
		std::cout << "-------------------\n";

		dflt.beRepaired(42);
		std::cout << "-------------------\n";
		dflt.meleeAttack("Zombie");
		std::cout << "-------------------\n";
		dflt.rangedAttack("Android");
		std::cout << "-------------------\n";
		dflt.takeDamage(200);
		std::cout << "-------------------\n";
		dflt.takeDamage(200);
		std::cout << "-------------------\n";
		dflt.beRepaired(21);
		std::cout << "-------------------\n";
		dflt.takeDamage(50);
		std::cout << "-------------------\n";
		dflt.beRepaired(300);
		std::cout << "-------------------\n";
		for (int i = 0; i < 6; i++)
			dflt.challengeNewcomer();
		std::cout << "-------------------\n";
		dflt.takeDamage(70);
		std::cout << "-------------------\n";
		dflt.beRepaired(40);
		std::cout << "-------------------\n";
		dflt.takeDamage(17);
		std::cout << "-------------------\n";
		dflt.takeDamage(10);
		std::cout << "-------------------\n";
		dflt.takeDamage(1);
		std::cout << "-------------------\n";
		dflt.takeDamage(60);
		std::cout << "-------------------\n";
		dflt.meleeAttack("Zombie");
		std::cout << "-------------------\n";
	}
	std::cout << "\n\033[1;36m PART 3 \033[0m\n\n";
	{
		ClapTrap clap;
		std::cout << "-------------------\n";
		ClapTrap to_copy(clap);
		std::cout << "-------------------\n";
	}
		std::cout << "\n\033[1;36m PART 4 \033[0m\n\n";
	{
		ClapTrap clap;
		std::cout << "-------------------\n";
		FragTrap frag("Bonnie");
		std::cout << "-------------------\n";
		ScavTrap scav("Sam");
		std::cout << "-------------------\n";
		NinjaTrap nin;
		std::cout << "-------------------\n";
		nin.beRepaired(21);
		std::cout << "-------------------\n";
		nin.takeDamage(200);
		std::cout << "-------------------\n";
		nin.beRepaired(100);
		std::cout << "-------------------\n";
		NinjaTrap name("Momochi");
		std::cout << "-------------------\n";
		nin.ninjaShoebox(scav);
		std::cout << "-------------------\n";
		nin.ninjaShoebox(clap);
		std::cout << "-------------------\n";
		nin.ninjaShoebox(frag);
		std::cout << "-------------------\n";
		nin.ninjaShoebox(name);
		std::cout << "-------------------\n";
		nin.takeDamage(200);
		std::cout << "-------------------\n";
		nin.ninjaShoebox(name);
		std::cout << "-------------------\n";
	}
	return (0);
}