#include "mutantstack.hpp"
#include <vector>
#include <set>
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

	char arr[] = {'c', 'a', 'b'};
	std::set<char> s(arr, arr + 3);

	MutantStack<int> a;
	MutantStack< int, std::vector<int> > m;
	MutantStack< int, std::vector<int> > c(v);
	MutantStack< char, std::set<char> > test(s);

	std::cout << "EMPTY MUTANTSATCK (DEQUE)\n";
	print_stack(a.cbegin(), a.cend(), a);
	std::cout << "--------------\n";

	std::cout << "EMPTY MUTANTSATCK (VECTOR)\n";
	print_stack(m.cbegin(), m.cend(), m);
	std::cout << "--------------\n";

	std::cout << "MUTANTSATCK (SET)\n";
	std::cout << "forward --->\n";
	print_stack(test.cbegin(), test.cend(), test);
	std::cout << "<--- reverse\n";
	print_stack(test.crbegin(), test.crend(), test);
	std::cout << "--------------\n";

	std::cout << "MUTANTSATCK (VECTOR)\n";
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

	std::cout << "CHANGE VALUES VIA ITERATOR\n";
	MutantStack< int, std::vector<int> >::iterator it = m.begin();
	while (it != m.end())
	{
		(*it)++;
		std::cout << *it++ << std::endl;
	}
	std::cout << "--------------\n";

	std::cout << "STACK FUNCTIONS\n";
	std::cout << "top element : " << m.top() << std::endl;
	std::cout << "pop one element\n";
	m.pop();
	std::cout << "top element : " << m.top() << " and size : " << m.size() << std::endl;
	m.push(77);
	std::cout << "push 77, top element : " << m.top() << std::endl;
	print_stack(m.cbegin(), m.cend(), m);
	std::cout << "--------------\n";

	return (0);
}