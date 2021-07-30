#ifndef MUTANTSTACK_CPP
# define MUTANTSTACK_CPP

#include <deque>
#include <stack>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(const Container &ctnr);
	MutantStack(const MutantStack &copy);
	virtual ~MutantStack();

	MutantStack &operator = (const MutantStack &copy);

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(void);
	iterator end(void);
	reverse_iterator rbegin(void);
	reverse_iterator rend(void);
	const_iterator cbegin(void) const;
	const_iterator cend(void) const;
	const_reverse_iterator crbegin(void) const;
	const_reverse_iterator crend(void) const;
};

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {};

template<class T, class Container>
MutantStack<T, Container>::MutantStack(const Container &ctnr) : std::stack<T, Container>(ctnr) {};

template<class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {};

template<class T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator = (const MutantStack &copy)
{
	this->c = copy.c;
	return (*this);
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {};

template<class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin(void) const
{
	return (this->c.cbegin());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend(void) const
{
	return (this->c.cend());
}

template<class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

template<class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin(void) const
{
	return (this->c.crbegin());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend(void) const
{
	return (this->c.crend());
}

#endif