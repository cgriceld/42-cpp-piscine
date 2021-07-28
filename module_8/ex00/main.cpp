#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>

template <typename T>
static void test(T &cont, int val)
{
	try
	{
		std::cout << *easyfind(cont, val) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << val << " - " << e.what() << '\n';
	}
}

int main(void)
{
	int arr[] = {5, 23, -8, 0, 4};

	std::cout << "VECTOR\n";
	std::vector<int> v(arr, arr + 5);
	test(v, 23);
	test(v, -3);
	std::cout << "--------------\n";

	std::cout << "LIST\n";
	std::list<int> l(arr, arr + 5);
	test(v, 0);
	test(v, -9);
	std::cout << "--------------\n";

	std::cout << "SET\n";
	std::set<int> s(arr, arr + 5);
	test(v, 4);
	test(v, -7);
	std::cout << "--------------\n";

	return (0);
}