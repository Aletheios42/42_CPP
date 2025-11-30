#include "../Inc/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level) {
    const std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*methods[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int idx_level = -1;

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level)
            idx_level = i;
    }

    if (idx_level == -1)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

    for (; idx_level >= 0; idx_level--)
        (this->*methods[idx_level])();
}

void Harl::debug() {
    std::cout << DEBUG_MSG << std::endl;
}

void Harl::info() {
    std::cout << INFO_MSG << std::endl;
}

void Harl::warning() {
    std::cout << WARNING_MSG << std::endl;
}

void Harl::error() {
    std::cout << ERROR_MSG << std::endl;
}
