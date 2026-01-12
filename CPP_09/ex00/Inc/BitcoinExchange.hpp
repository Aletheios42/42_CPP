#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, float> _db;

    std::string trim(const std::string& str);
    bool        isValidDate(const std::string& date);
    bool        isValidValue(const std::string& valueStr, float& value);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    ~BitcoinExchange();

    void    loadDatabase(const std::string& filename);
    void    processInput(const std::string& filename);
};

#endif