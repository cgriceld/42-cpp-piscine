#include <iostream>
#include <cctype>

/*
** Displays "noise" when program is run without arguments,
** otherwise displays argument in upper case.
*/

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}

	return (0);
}