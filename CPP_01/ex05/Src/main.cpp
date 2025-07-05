#include "../Inc/Harl.hpp"


int main(int ac, char **av)
{

    Harl harl;

    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("DEBUG");

    return 0;
}

