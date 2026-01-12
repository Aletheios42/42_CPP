#include <iostream>
#include <string>
#include <exception>

#include "../Inc/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat ramon("ramon", 1);
		std::cout << ramon << std::endl;
		for (size_t i = 0; i < 149; i++)
			ramon.decrementGrade();
		std::cout << ramon << std::endl;
		ramon.decrementGrade();
		std::cout << ramon << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat manuel("manuel", 42);
		Bureaucrat npc("NPC", 142);
		Bureaucrat unk(npc);
		Bureaucrat nown = manuel;
		npc = manuel;
		npc.incrementGrade();
		std::cout << npc << std::endl;
		std::cout << unk << std::endl;
		std::cout << nown << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat lingxiaoHeLin("Lingxiao He Lin", 1);
	std::cout << lingxiaoHeLin << std::endl;
	try
	{
		lingxiaoHeLin.incrementGrade();
		std::cout << lingxiaoHeLin << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "inside the 'catch'" << std::endl;
		std::cout << lingxiaoHeLin << std::endl;
	}
	
	return (0);
}
