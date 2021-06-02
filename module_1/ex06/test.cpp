#include <iostream>

int main(void)
{
	int i = 42;
	int &ref = i;
	std::cout << ref << std::endl;
	std::cout << i << std::endl;
	int a = 21;
	ref = a;
	std::cout << ref << std::endl;
	std::cout << i << std::endl;

	return(0);
}