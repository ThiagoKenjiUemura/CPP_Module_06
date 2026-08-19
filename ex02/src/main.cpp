#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "[Gerador] Instanciou a classe: A" << std::endl;
		return new A;
	}
	else if (random == 1)
	{
		std::cout << "[Gerador] Instanciou a classe: B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "[Gerador] Instanciou a classe: C" << std::endl;
		return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "[Ponteiro] Identificado como: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "[Ponteiro] Identificado como: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "[Ponteiro] Identificado como: C" << std::endl;
	else
		std::cout << "[Ponteiro] Tipo desconhecido!" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "[Referencia] Identificada como: A" << std::endl;
		return;
	} 
	catch (const std::exception& e) {}

	try 
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "[Referencia] Identificada como: B" << std::endl;
		return;
	} 
	catch (const std::exception& e) {}

	try 
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "[Referencia] Identificada como: C" << std::endl;
		return;
	} 
	catch (const std::exception& e) {}

	std::cout << "[Referencia] Tipo desconhecido!" << std::endl;
}

int main()
{
	std::srand(time(NULL));

	std::cout << "--- TESTE 1 ---" << std::endl;
	Base* obj1 = generate();
	identify(obj1);
	identify(*obj1);
	delete obj1;

	std::cout << "\n--- TESTE 2 ---" << std::endl;
	Base* obj2 = generate();
	identify(obj2);
	identify(*obj2);
	delete obj2;

	std::cout << "\n--- TESTE 3 ---" << std::endl;
	Base* obj3 = generate();
	identify(obj3);
	identify(*obj3);
	delete obj3;

	return 0;
}