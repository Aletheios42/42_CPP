#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

#define DEBUG_MSG   "\033[36mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m"
#define INFO_MSG    "\033[32mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m"
#define WARNING_MSG "\033[33mI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\033[0m"
#define ERROR_MSG   "\033[31mThis is unacceptable! I want to speak to the manager now.\033[0m"

class Harl {
    public:
        Harl();
        ~Harl();
        void complain( std::string level);
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};
