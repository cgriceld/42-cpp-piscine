#include <iostream>

int main(void)
{
	int i = 42;
	const int &ref = i;
	std::cout << ref << std::endl;
	std::cout << i << std::endl;
	i = 21;
	std::cout << ref << std::endl;
	std::cout << i << std::endl;

	return(0);
}