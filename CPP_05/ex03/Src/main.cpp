#include <iostream>
#include <string>
#include <exception>
#include <cstdlib> 
#include <ctime>

#include "../Inc/Bureaucrat.hpp"
#include "../Inc/ShrubberyCreationForm.hpp"
#include "../Inc/RobotomyRequestForm.hpp"
#include "../Inc/PresidentialPardonForm.hpp"
#include "../Inc/Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	try
	{
		Bureaucrat god("God", 1);
		Intern doomer;
		std::string target = "yo_mama";
		AForm *shru = doomer.makeForm("shrubbery creation", target);
		AForm *robo = doomer.makeForm("robotomy request", target);
		AForm *pres = doomer.makeForm("presidential pardon", target);
		AForm *unkn = doomer.makeForm("phone call", target);

		if (shru)
		{
			god.signForm(*shru);
			god.executeForm(*shru);
		}

		if (robo)
		{
			god.signForm(*robo);
			god.executeForm(*robo);
		}

		if (pres)
		{
			god.signForm(*pres);
			god.executeForm(*pres);
		}

		if (unkn)
		{
			god.signForm(*unkn);
			god.executeForm(*unkn);
		}

		delete shru;
		delete robo;
		delete pres;
		delete unkn;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    return (0);
}