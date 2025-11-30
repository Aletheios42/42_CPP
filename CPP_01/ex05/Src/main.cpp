#include "../Inc/Harl.hpp"


int main(int ac, char **av)
{

    Harl harl;

    std::cout << " testing ERROR" << std::endl;
    harl.complain("ERROR");
    std::cout << " testing WARNING" << std::endl;
    harl.complain("WARNING");
    std::cout << " testing INFO" << std::endl;
    harl.complain("INFO");
    std::cout << " testing DEBUG" << std::endl;
    harl.complain("DEBUG");

    return 0;
}

