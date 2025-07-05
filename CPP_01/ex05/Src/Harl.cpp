#include "../Inc/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain( std::string level) {
    const std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*methods[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            for (int j = i; j < 4; ++j)
                (this->*methods[j])();
            return;
        }
    }
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
