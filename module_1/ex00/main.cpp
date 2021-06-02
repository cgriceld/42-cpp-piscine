#include "Pony.hpp"

static void ponyOnTheHeap(void)
{
	Pony *pony;

	try
	{
		pony = new Pony("heap");
	}
	catch (const std::bad_alloc &ba)
	{
		std::cerr << "No space for new pony : " << ba.what() << std::endl;
		return;
	}
	pony->introduce();
	delete pony;
}

static void ponyOnTheStack(void)
{
	Pony pony(10, "Camelot", "stack");
	pony.introduce();
}

int main(void)
{
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();

	return (0);
}