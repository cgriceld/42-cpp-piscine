#include "mutantstack.hpp"
#include <vector>
#include <iostream>

template <typename I, class T, class Container>
void print_stack(I begin, I end, std::stack<T, Container> &c)
{
	std::cout << "size : " << c.size() << std::endl;
	while (begin != end)
		std::cout << *begin++ << std::endl;
}

int main(void)
{
	std::vector<int> v;
	v.push_back(21);
	v.push_back(42);
	v.push_back(11);

	MutantStack<int> a;
	MutantStack< int, std::vector<int> > m;
	MutantStack< int, std::vector<int> > c(v);

	std::cout << "EMPTY MUTANTSATCK (DEQUE)\n";
	print_stack(a.cbegin(), a.cend(), a);
	std::cout << "--------------\n";

	std::cout << "EMPTY MUTANTSATCK (VECTOR)\n";
	print_stack(m.cbegin(), m.cend(), m);
	std::cout << "--------------\n";

	std::cout << "COPY MUTANTSATCK (VECTOR)\n";
	std::cout << "forward --->\n";
	print_stack(c.cbegin(), c.cend(), c);
	std::cout << "<--- reverse\n";
	print_stack(c.crbegin(), c.crend(), c);
	std::cout << "--------------\n";

	std::cout << "COPY MUTANTSATCK\n";
	MutantStack< int, std::vector<int> > copy(c);
	copy.push(90);
	print_stack(copy.cbegin(), copy.cend(), copy);
	std::cout << "--------------\n";

	std::cout << "= OPERATOR MUTANTSATCK\n";
	m = copy;
	print_stack(m.cbegin(), m.cend(), m);
	std::cout << "--------------\n";

	return (0);
}