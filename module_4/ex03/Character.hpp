#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character(const std::string &name);
	Character(const Character &copy);
	virtual ~Character();

	Character &operator = (const Character &copy);

	std::string const &getName(void) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string _name;
	AMateria *_materials[4];

	Character();
	void free_mat(void);
	void copy_elems(const Character &copy);
};

#endif