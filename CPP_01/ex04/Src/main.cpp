#include "../Inc/sed.hpp"


int main(int ac, char **av)
{
    if (ac != 4)
        return 0;

    std::ifstream file(av[1]);
    if (!file.is_open())
        return 1;

    std::string nuevo_archivo = std::string(av[1]) + ".replace";
    std::ofstream outfile(nuevo_archivo.c_str());
    if (!outfile.is_open())
        return 1;

    std::string linea;
    const std::string buscar = av[2];
    const std::string reemplazar = av[3];

    while (std::getline(file, linea)) {
        size_t pos = 0;
        while ((pos = linea.find(buscar, pos)) != std::string::npos) {
            linea.replace(pos, buscar.length(), reemplazar);
            pos += reemplazar.length();
        }
        outfile << linea << "\n";
    }

    return 0;
}

