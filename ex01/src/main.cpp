#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data meuDado;
	meuDado.id = 42;
	meuDado.name = "Projeto de C++";
	meuDado.level = 9000.1f;

	Data* ponteiroOriginal = &meuDado;

	uintptr_t dadoSerializado = Serializer::serialize(ponteiroOriginal);

	Data* ponteiroRestaurado = Serializer::deserialize(dadoSerializado);

	std::cout << "--- TESTE DE SERIALIZACAO ---" << std::endl;
	
	std::cout << "Endereco Original:   " << ponteiroOriginal << std::endl;
	std::cout << "Valor Serializado:   0x" << std::hex << dadoSerializado << std::endl;
	std::cout << "Endereco Restaurado: " << ponteiroRestaurado << std::endl;

	std::cout << "\n--- TESTE DE DADOS ---" << std::endl;

	if (ponteiroOriginal == ponteiroRestaurado)
	{
		std::cout << "[SUCESSO] Os ponteiros sao identicos!" << std::endl;
		std::cout << "ID: " << std::dec << ponteiroRestaurado->id << std::endl;
		std::cout << "Nome: " << ponteiroRestaurado->name << std::endl;
		std::cout << "Level: " << ponteiroRestaurado->level << std::endl;
	}
	else
	{
		std::cout << "[ERRO] Os ponteiros sao diferentes. Perda de dados!" << std::endl;
	}

	return 0;
}
