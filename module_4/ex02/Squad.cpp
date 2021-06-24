#include "Squad.hpp"

Squad::Squad() : _capacity(3), _count(0)
{
	try
	{
		_squad = new ISpaceMarine *[_capacity];
	}
	catch(const std::bad_alloc &e)
	{
		squad_error(e);
		return;
	}
	std::cout << "/Squad default constructor/\n";
}

Squad::Squad(const Squad &copy)
{
	*this = copy;
	std::cout << "/Squad copy constructor/\n";
}

Squad::~Squad()
{
	free_squad();
	std::cout << "/Squad destructor/\n";
};

Squad &Squad::operator = (const Squad &copy)
{
	if (this == &copy)
		return (*this);
	free_squad();
	_capacity = copy._capacity;
	_count = copy._count;
	try
	{
		_squad = _capacity ? new ISpaceMarine *[_capacity] : NULL;
	}
	catch(const std::bad_alloc &e)
	{
		squad_error(e);
		return (*this);
	}
	for (int i = 0; i < _count; i++)
		_squad[i] = copy._squad[i]->clone();
	std::cout << "/Assignation operator/\n";
	return (*this);
}

int Squad::getCount(void) const
{
	return (_count);
}

ISpaceMarine *Squad::getUnit(int i) const
{
	return ((!_squad || i < 0 || i >= _count) ? NULL : _squad[i]);
}

bool Squad::is_in(ISpaceMarine *elem) const
{
	for (int i = 0; i < _count; i++)
	{
		if (_squad[i] == elem)
			return (true);
	}
	return (false);
}

int Squad::push(ISpaceMarine *elem)
{
	if (!_squad || !elem || is_in(elem))
		return (_count);
	if (_count + 1 > _capacity)
	{
		_capacity *= 2;
		try
		{
			ISpaceMarine **tmp = new ISpaceMarine *[_capacity];
			for (int i = 0; i < _count; i++)
				tmp[i] = _squad[i];
			delete[] _squad;
			_squad = tmp;
		}
		catch(const std::bad_alloc &e)
		{
			std::cerr << e.what() << ": no push is available\n";
			return (_count);
		}
	}
	_squad[_count++] = elem;
	return (_count);
}

void Squad::free_squad(void)
{
	for (int i = 0; i < _count; i++)
		delete _squad[i];
	delete[] _squad;
	std::cout << "/Free squad/\n";
}

void Squad::squad_error(const std::bad_alloc &e)
{
	std::cerr << e.what() << ": no squad was created\n";
	_squad = NULL;
	_capacity = 0;
}