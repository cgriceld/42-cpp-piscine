#include <iostream>
#include <string>
#include <fstream>

static void sed(std::ifstream &file, std::ofstream &replace, std::string &to_find, std::string &to_replace)
{
	size_t i = 0;
	std::string line;

	while (std::getline(file, line))
	{
		while ((i = line.find(to_find)) != std::string::npos)
		{
			line.replace(i, to_find.length(), to_replace);
			i += to_replace.length();
		}
		replace << line;
		if (!file.eof())
			replace << std::endl;
	}
	if (!file.eof())
		std::cerr << "Error while reading" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of argumnets" << std::endl;
		return (1);
	}

	std::ifstream file;
	std::ofstream replace;
	std::string to_find(argv[2]);
	std::string to_replace(argv[3]);
	std::string new_file(argv[1]);

	file.open(argv[1], std::ifstream::in);
	for (size_t i = 0; i < new_file.length(); i++)
		new_file[i] = std::toupper(new_file[i]);
	replace.open(new_file + ".replace", std::ofstream::trunc);
	if (file.fail() || replace.fail() || !to_find.length() || !to_replace.length())
	{
		std::cerr << "Error with arguments (no such file, error while opening, empty arguments)" << std::endl;
		return (1);
	}
	sed(file, replace, to_find, to_replace);
	file.close();
	replace.close();
	return (0);
}