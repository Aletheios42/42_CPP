#include "../Inc/Harl.hpp"


int main(int ac, char **av)
{

    Harl harl;

    if (ac == 2) {
        harl.complain("ERROR", av[1]);
        harl.complain("WARNING", av[1]);
        harl.complain("INFO", av[1]);
        harl.complain("DEBUG", av[1]);
    }

    return 0;
}

