#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_materials[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	copy_elems(copy);
}

MateriaSource::~MateriaSource()
{
	free_mat();
}

MateriaSource &MateriaSource::operator = (const MateriaSource &copy)
{
	if (this == &copy)
		return (*this);
	free_mat();
	copy_elems(copy);
	return (*this);
}

void MateriaSource::free_mat(void)
{
	for (int i = 0; i < 4; ++i)
		delete _materials[i];
}

void MateriaSource::copy_elems(const MateriaSource &copy)
{
	for (int i = 0; i < 4; ++i)
		_materials[i] = copy._materials[i] ? copy._materials[i]->clone() : NULL;
}

void MateriaSource::learnMateria(AMateria *m)
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

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materials[i] && !_materials[i]->getType().compare(type))
			return (_materials[i]->clone());
	}
	return (NULL);
}