#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
public:
	Character(std::string const &name);
	Character(const Character &copy);
	virtual ~Character();

	Character &operator = (const Character &copy);

	void recoverAP(void);
	void equip(AWeapon *wep);
	void attack(Enemy *en);

	std::string const &getName(void) const;
	int get_ap(void) const;
	AWeapon *get_weapon(void) const;

protected:
	std::string _name;
	int _ap;
	AWeapon *_weapon;

private:
	Character();
};

std::ostream &operator << (std::ostream &stream, const Character &ch);

#endif