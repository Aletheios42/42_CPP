#include <iostream>
#include <string>
#include <exception>

#include "../Inc/Bureaucrat.hpp"
#include "../Inc/AForm.hpp"
#include "../Inc/ShrubberyCreationForm.hpp"
#include "../Inc/PresidentialPardonForm.hpp"
#include "../Inc/RobotomyRequestForm.hpp"

int main()
{
	// std::srand(std::time(NULL)); // Inicializa la semilla para rand() una sola vez

    try
	{
		Bureaucrat signer("El Firmas", 25);
		Bureaucrat exe("Ejecutor", 5);
		Bureaucrat egg("Exeggutor", 45);

		AForm *shru = new ShrubberyCreationForm("Deku");
		AForm *robo = new RobotomyRequestForm("Master Chief");
		AForm *pres = new PresidentialPardonForm("Bumblebee");

		signer.signForm(*shru);
		signer.signForm(*robo);
		signer.signForm(*pres);

		exe.executeForm(*shru);
		exe.executeForm(*robo);
		exe.executeForm(*pres);

		delete shru;
		delete robo;
		delete pres;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    
    return (0);
}
