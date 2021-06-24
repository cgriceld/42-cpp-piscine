#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const std::string &name);
	MateriaSource(const MateriaSource &copy);
	virtual ~MateriaSource();

	MateriaSource &operator = (const MateriaSource &copy);

	void learnMateria(AMateria *m);
	AMateria* createMateria(std::string const & type);

private:
	AMateria *_materials[4];

	void free_mat(void);
	void copy_elems(const MateriaSource &copy);
};

#endif