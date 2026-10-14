#include "../includes/ScalarConverter.hpp"

static bool parseNumber(const std::string &str, eType type, double &value)
{
	std::string input = str;
	char *end;

	if (type == FLOAT)
		input.erase(input.length() - 1);
	errno = 0;
	value = std::strtod(input.c_str(), &end);
	if (end == input.c_str() || *end != '\0' || errno == ERANGE)
		return (false);
	return (true);
}

static void printChar(double value)
{
	if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
}

static void printInt(double value)
{
	if (value < INT_MIN || value > INT_MAX || value != static_cast<long>(value))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";
}

static void printFloating(double value, eType type)
{
	std::cout << std::fixed << std::setprecision(1);
	if (type == FLOAT)
		std::cout << "float: " << static_cast<float>(value) << "f\n";
	else
		std::cout << "double: " << value << "\n";
}

static void printSpecial(const std::string &str)
{
	bool negative = str[0] == '-';
	bool nan = str[0] == 'n';

	std::cout << "char: impossible\nint: impossible\n";
	if (nan)
		std::cout << "float: nanf\ndouble: nan\n";
	else if (negative)
		std::cout << "float: -inff\ndouble: -inf\n";
	else
		std::cout << "float: +inff\ndouble: +inf\n";
}

void doConvert(const std::string &str, eType type)
{
	double value;

	if (type == SPECIAL)
	{
		printSpecial(str);
		return;
	}
	if (type == CHAR)
		value = static_cast<unsigned char>(str[0]);
	else if (!parseNumber(str, type, value))
	{
		std::cout << "char: impossible\nint: impossible\n"
				  << "float: impossible\ndouble: impossible" << std::endl;
		return;
	}
	printChar(value);
	printInt(value);
	printFloating(value, FLOAT);
	printFloating(value, DOUBLE);
}
