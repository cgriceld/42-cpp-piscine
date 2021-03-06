#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

static void char_int_imp(void)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
}

static void nanf(std::string val)
{
	char_int_imp();
	std::cout << "float: " << val << std::endl;
	val.resize(val.length() - 1);
	std::cout << "double: " << val << std::endl;
}

static void nan(const std::string val)
{
	char_int_imp();
	std::cout << "float: " << val + "f" << std::endl;
	std::cout << "double: " << val << std::endl;
}

template <typename T>
static void char_limits(T tmp)
{
	std::cout << "char: ";
	if (tmp < std::numeric_limits<char>::min() || tmp > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(tmp))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(tmp) << "'" << std::endl;
}

template <typename T>
static void int_limits(T tmp)
{
	std::cout << "int: ";
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(tmp) << std::endl;
}


static void convert_double(const std::string val)
{
	size_t idx;
	double tmp = std::stod(val, &idx);
	if (val.length() != idx)
		throw std::invalid_argument("");
	char_limits(tmp);
	int_limits(tmp);
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << tmp << std::endl;
}

static void convert_float(std::string val)
{
	val.pop_back();
	size_t idx;
	float tmp = std::stof(val, &idx);
	if (val.length() != idx)
		throw std::invalid_argument("");
	char_limits(tmp);
	int_limits(tmp);
	std::cout << "float: " << tmp << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

static void convert_int(const std::string val)
{
	size_t idx;
	int tmp = std::stoi(val, &idx);
	if (val.length() != idx)
		throw std::invalid_argument("");
	char_limits(tmp);
	std::cout << "int: " << tmp << std::endl;
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

static void convert_char(const char ch)
{
	std::cout << "char: '" << ch << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << static_cast<float>(ch) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ch) << std::endl;
}

static void get_type(const std::string &val)
{
	if (val.length() == 3 && val.front() == '\'' && val.front() == val.back())
		convert_char(val.at(1));
	else
	{
		try
		{
			if (!val.compare("-inff") || !val.compare("+inff") || !val.compare("nanf"))
				nanf(val);
			else if (!val.compare("-inf") || !val.compare("+inf") || !val.compare("nan"))
				nan(val);
			else if (val.back() == 'f' && val.find('.') != std::string::npos)
				convert_float(val);
			else if (val.find('.') != std::string::npos)
				convert_double(val);
			else
				convert_int(val);
		}
		catch(const std::out_of_range &e)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << "conversion is impossible\n";
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Usage : ./convert [non-empty value], try again\n";
		return (1);
	}
	std::cout << std::fixed << std::setprecision(1);
	get_type(argv[1]);
	return (0);
}