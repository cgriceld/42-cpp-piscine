#include "Pony.hpp"

static void ponyOnTheHeap(void)
{
	Pony *pony;

	pony = new Pony("heap");
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