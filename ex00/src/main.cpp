#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Uso correto: ./convert <literal_cpp>" << std::endl;
        std::cout << "Exemplo: ./convert 42.0f" << std::endl;
        return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
