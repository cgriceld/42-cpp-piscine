#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
class ICharacter;

class AMateria
{
public:
	AMateria(const std::string &type);
	AMateria(const AMateria &copy);
	virtual ~AMateria();

	AMateria &operator = (const AMateria &copy);

	std::string const &getType(void) const;
	unsigned int getXP(void) const;
	virtual void use(ICharacter& target);
	virtual AMateria *clone(void) const = 0;

protected:
	unsigned int _xp;
	std::string _type;

private:
	AMateria();
};

#endif