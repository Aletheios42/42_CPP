#include "../Inc/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level) {
    const std::string levels[] = { "ERROR", "WARNING", "DEBUG", "INFO", "DEFAULT"};
    void (Harl::*methods[])(void) = {
        &Harl::error,
        &Harl::warning,
        &Harl::info,
        &Harl::debug,
        &Harl::default_complain
    };

    int idx = -1;

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level)
            idx = i;
    }

switch (idx) {
    case 0:
        (this->*methods[0])();
        /* fall through */
    case 1:
        (this->*methods[1])();
        /* fall through */
    case 2:
        (this->*methods[2])();
        /* fall through */
    case 3:
        (this->*methods[3])();
        break;
    default:
        (this->*methods[4])();
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

void Harl::default_complain() {
    std::cout << DEFAULT_MSG << std::endl;
}
