#ifndef MUTANTSTACK_CPP
# define MUTANTSTACK_CPP

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(const Container &ctnr);
	MutantStack(const MutantStack &copy);
	virtual ~MutantStack();

	MutantStack &operator = (const MutantStack &copy);
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
	std::stack<T, Container>::operator=(copy);
	// return?
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {};

#endif