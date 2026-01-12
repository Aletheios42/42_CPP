#include <iostream>
#include <string>
#include <exception>

#include "../Inc/Bureaucrat.hpp"
#include "../Inc/Form.hpp"

int main()
{
    try
    {
        Bureaucrat carrera("José Miguel Carrera", 1);
        Bureaucrat español("Gobernador Español", 150);
        Bureaucrat mapuche("Toqui", 42);
		//Bureaucrat anacronismo("Augusto Pinochet", 999); // Exception

        Form independencia("Acta de Independencia de Chile", 1, 1);
        Form permisoReal("Permiso Real de España", 150, 150);
        Form pachamama("Qulqi Uru", 42, 42);
		//Form anacronismoForm("Cerveza Cristal", 999, 999); // Exception

        std::cout << carrera << std::endl;
        std::cout << español << std::endl;
        std::cout << mapuche << std::endl;
        std::cout << independencia << std::endl;
        std::cout << permisoReal << std::endl;
        std::cout << pachamama << std::endl;

        carrera.signForm(independencia);
        español.signForm(permisoReal);
        español.signForm(pachamama);

        std::cout << independencia << std::endl;
        std::cout << permisoReal << std::endl;
        std::cout << pachamama << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
