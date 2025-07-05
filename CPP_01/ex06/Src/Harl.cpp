#include "../Inc/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level, std::string minimum) {
    const std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*methods[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int idx_level = -1;
    int idx_minimum = -1;

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level)
            idx_level = i;
        if (levels[i] == minimum)
            idx_minimum = i;
    }

    if (idx_level == -1 || idx_minimum == -1 || idx_level < idx_minimum)
        return;

    for (int i = idx_level; i < 4; ++i)
        (this->*methods[i])();
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
