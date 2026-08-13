#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter Copy Constructor called." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter Copy Assignment Operator called." << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called." << std::endl;
}


void ScalarConverter::convert(const std::string& literal)
{
	e_type type = identifyType(literal);
	if (type == UNKNOWN)
	{
		std::cout << "Erro: Tipo não reconhecido." << std::endl;
		return;
	}

	if (type == PSEUDO)
	{
		std::cout << "char: impossível" << std::endl;
		std::cout << "int: impossível" << std::endl;
		if (literal == "nan" || literal == "nanf") {
			std::cout << "float: nanf\ndouble: nan\n";
		} else if (literal == "+inf" || literal == "+inff") {
			std::cout << "float: +inff\ndouble: +inf\n";
		} else if (literal == "-inf" || literal == "-inff") {
			std::cout << "float: -inff\ndouble: -inf\n";
		}
		return;
	}

	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	switch (type)
	{
		case CHAR:
			c = literal[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT:
			i = static_cast<int>(std::strtol(literal.c_str(), NULL, 10));
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT:
			f = static_cast<float>(std::strtod(literal.c_str(), NULL));
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = std::strtod(literal.c_str(), NULL);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		default:
			break;
	}

	if (i >= 0 && i <= 127)
	{
		if(std::isprint(i))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: impossível" << std::endl;
	}

	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout<< "f" << std::endl;

	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

ScalarConverter::e_type ScalarConverter::identifyType(const std::string& literal)
{
	if (isPseudo(literal))			return PSEUDO;
	if (isChar(literal))			return CHAR;
	if (isInt(literal))				return INT;
	if (isFloat(literal))			return FLOAT;
	if (isDouble(literal))			return DOUBLE;

	return UNKNOWN;
}

bool ScalarConverter::isPseudo(const std::string& literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
			literal == "-inf"  || literal == "+inf"  || literal == "nan");
}

bool ScalarConverter::isChar(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
	{
		start = 1;
		if (literal.length() == 1)
			return false;
	}
	for(size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}
bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t start = 0;
	size_t count_point = 0;
	bool found_digit = false;
	
	if (literal[0] == '+' || literal[0] == '-')
	{
		start = 1;
		if (literal.length() == 1)
			return false;
	}

	for(size_t i = start; i < literal.length() - 1; i++)
	{
		if (std::isdigit(literal[i]))
			found_digit = true;
		else if(literal[i] == '.')
			count_point++;
		else
			return false;
		if (count_point > 1)
			return false;
	}
	if (literal[literal.length() - 1] != 'f')
		return false;

	return found_digit;
}
bool ScalarConverter::isDouble(const std::string& literal)
{
if (literal.empty())
		return false;

	size_t start = 0;
	size_t count_point = 0;
	bool found_digit = false;
	
	if (literal[0] == '+' || literal[0] == '-')
	{
		start = 1;
		if (literal.length() == 1)
			return false;
	}

	for(size_t i = start; i < literal.length(); i++)
	{
		if (std::isdigit(literal[i]))
			found_digit = true;
		else if(literal[i] == '.')
			count_point++;
		else
			return false;
		if (count_point > 1)
			return false;
	}
	return (found_digit && count_point == 1);
}
