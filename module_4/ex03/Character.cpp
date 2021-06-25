#include "Character.hpp"

Character::Character() {};

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_materials[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name)
{
	copy_elems(copy);
}

Character &Character::operator = (const Character &copy)
{
	if (this == &copy)
		return (*this);
	free_mat();
	copy_elems(copy);
	return (*this);
}

Character::~Character()
{
	free_mat();
};

void Character::free_mat(void)
{
	for (int i = 0; i < 4; ++i)
	{
		delete _materials[i];
		_materials[i] = NULL;
	}
}

void Character::copy_elems(const Character &copy)
{
	for (int i = 0; i < 4; ++i)
		_materials[i] = copy._materials[i] ? copy._materials[i]->clone() : NULL;
}

std::string const &Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_materials[i])
		{
			_materials[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_materials[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _materials[idx])
		_materials[idx]->use(target);
}