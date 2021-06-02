#include <string>
#include <iostream>

int main(void)
{
	std::string test("HI THIS IS BRAIN");

	std::string *ptr;
	ptr = &test;

	std::string &ref = test;

	std::cout << "Using pointer : " << *ptr << "; using reference : " << ref << std::endl;

	return (0);
}