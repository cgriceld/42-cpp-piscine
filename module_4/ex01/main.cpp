#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Crossbow.hpp"
#include "Clicker.hpp"

int main(void)
{
	Character* me = new Character("me");
	std::cout << *me;

	Enemy* scorp = new RadScorpion();
	Enemy* mut = new SuperMutant();
	Enemy* click = new Clicker();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* cb = new Crossbow();

	std::cout << "----------------------\n";

	me->equip(NULL);
	me->attack(scorp);
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(scorp);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(scorp);
	std::cout << *me;
	me->attack(scorp);
	std::cout << *me;
	me->attack(NULL);

	std::cout << "----------------------\n";

	me->equip(cb);
	std::cout << *me;
	me->attack(mut);
	std::cout << *me;
	for (int i = 0; i < 3; i++)
	{
		me->recoverAP();
		std::cout << *me;
	}
	me->attack(mut);
	std::cout << *me;
	me->recoverAP();
	me->equip(pf);
	std::cout << *me;
	me->attack(mut);
	std::cout << *me;
	for (int i = 0; i < 2; i++)
	{
		me->recoverAP();
		std::cout << *me;
		me->attack(mut);
		std::cout << *me;
	}

	std::cout << "----------------------\n";

	me->recoverAP();
	std::cout << *me;
	me->attack(click);
	std::cout << *me;
	me->equip(NULL);
	std::cout << *me;

	delete me;
	delete pr;
	delete pf;
	delete cb;

	return (0);
}