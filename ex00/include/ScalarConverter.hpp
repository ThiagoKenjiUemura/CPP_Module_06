#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		enum e_type{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			UNKNOWN
		};

		static e_type identifyType(const std::string& literal);
		static bool isChar(const std::string& literal);
		static bool isPseudo(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);

	public:
		static void convert(const std::string& literal);
};

#endif