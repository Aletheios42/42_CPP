#include "../Inc/sed.hpp"


int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Uso: " << av[0] << " <archivo> <cadena_a_buscar> <cadena_de_reemplazo>" << std::endl;
        return 0;
    }

    const std::string nombre_archivo = av[1];
    const std::string buscar = av[2];
    const std::string reemplazar = av[3];

    if (buscar.empty())
    {
        std::cerr << "Error: La cadena a buscar no puede estar vacía." << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(nombre_archivo.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: No se pudo abrir el archivo de entrada: " << nombre_archivo << std::endl;
        return EXIT_FAILURE;
    }

    std::string nuevo_archivo = nombre_archivo + ".replace";

    std::ofstream outfile(nuevo_archivo.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: No se pudo crear el archivo de salida: " << nuevo_archivo << std::endl;
        file.close();
        return EXIT_FAILURE;
    }

    std::string linea;
    
    while (std::getline(file, linea))
    {
        size_t pos = 0;
        while ((pos = linea.find(buscar, pos)) != std::string::npos)
        {
            linea.erase(pos, buscar.length());
            linea.insert(pos, reemplazar);
            pos += reemplazar.length();
        }
        outfile << linea << "\n";
    }

    file.close(); 
    outfile.close(); 
    return 0;
}
