#include <iostream>

class Test
{
	public:
		static int i;

		static void incr(void)
		{
			i++;
		}
};

int Test::i = 4;

int main(void)
{
	std::cout << Test::i << "\n";
	Test::incr();
	Test a;
	a.i++;
	Test b;
	std::cout << b.i << "\n";

	return(0);
}