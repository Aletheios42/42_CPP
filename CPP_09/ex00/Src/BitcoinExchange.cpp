#include "../Inc/../Inc/BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _btcRates(other._btcRates), _userInput(other._userInput) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs) {
        _btcRates = rhs._btcRates;
        _userInput = rhs._userInput;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::trim(std::string& s) const {
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;
    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;
    s = s.substr(start, end - start);
}

void BitcoinExchange::validateDate(const std::string& date_str) const {
    if (date_str.size() != 10) {
        throw InvalidInputException();
    }
    if (date_str[4] != '-') {
        throw InvalidInputException();
    }
    if (date_str[7] != '-') {
        throw InvalidInputException();
    }

    for (size_t i = 0; i < date_str.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(static_cast<unsigned char>(date_str[i]))) {
            throw InvalidInputException();
        }
    }

    int year = std::atoi(date_str.substr(0, 4).c_str());
    int month = std::atoi(date_str.substr(5, 2).c_str());
    int day = std::atoi(date_str.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
        throw InvalidInputException();
    }

    static const int days_in_month[12] = {
        31,28,31,30,31,30,31,31,30,31,30,31
    };
    int dim = days_in_month[month - 1];
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (leap && month == 2) dim = 29;

    if (day < 1 || day > dim) {
        std::cerr << "[DEBUG] Fail: invalid day " << day << " for month " << month << std::endl;
        throw InvalidInputException();
    }
}

void BitcoinExchange::validateValue(const std::string& value_str) const {
    if (value_str.empty()) throw InvalidInputException();

    char* endptr = 0;
    double val = std::strtod(value_str.c_str(), &endptr);
    if (*endptr != '\0' || val < 0.0 || val > 1000.0)
        throw InvalidInputException();
}

bool BitcoinExchange::parseLine(const std::string& line, char delim,
                               std::string& date, std::string& value) const {
    size_t pos = line.find(delim);
    if (pos == std::string::npos)
        return false;
    date = line.substr(0, pos);
    value = line.substr(pos + 1);
    trim(date);
    trim(value);
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) throw InvalidInputException();

    std::string line;
    // Si el primer getline es cabecera, la ignoramos
    if (!std::getline(file, line)) throw InvalidInputException();

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::string date, value_str;
        if (!parseLine(line, ',', date, value_str))
            throw InvalidInputException();

        _btcRates[date] = value_str;
    }
    file.close();
}


void BitcoinExchange::loadUserInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) throw InvalidInputException();

    std::string line;
    while (std::getline(file, line)) {
        std::string date, value_str;
        if (line.empty())
            break;
        try {
            parseLine(line, '|', date, value_str);
            _userInput[date] = value_str;
        } catch (const InvalidInputException&) {
            std::cerr << "Invalid line detected: '" << line << "'" << std::endl;
            throw;
        }
    }
    file.close();
}

void BitcoinExchange::processData(const std::map<std::string, std::string>& btcRates,
                                  const std::map<std::string, std::string>& userInput) {
    std::map<std::string, std::string>::const_iterator it;
    for (it = userInput.begin(); it != userInput.end(); ++it) {
        const std::string& date = it->first;
        const std::string& valueStr = it->second;
        double value;

        std::cerr << "[DEBUG] Processing line: " << date << " | " << valueStr << std::endl;

        try {
            validateDate(date);
            validateValue(valueStr);
            value = std::atof(valueStr.c_str());
            std::cerr << "[DEBUG] Parsed value: " << value << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: bad input => " << date << " | " << e.what() << std::endl;
            continue;
        }

        if (value < 0.0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000.0) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, std::string>::const_iterator rateIt = btcRates.upper_bound(date);
        if (rateIt == btcRates.begin()) {
            std::cerr << "Error: no exchange rate available for " << date << std::endl;
            continue;
        }
        --rateIt;

        std::cerr << "[DEBUG] Matched rate: " << rateIt->first << " -> " << rateIt->second << std::endl;

        double rate = std::atof(rateIt->second.c_str());
        std::cerr << "[DEBUG] Parsed rate: " << rate << std::endl;

        double result = rate * value;
        std::cerr << "[DEBUG] Computed result: " << rate << " * " << value << " = " << result << std::endl;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

void BitcoinExchange::printDatabase(const std::string& title, const std::map<std::string, std::string>& db) const {
    std::cout << "--- " << title << " ---" << std::endl;
    std::map<std::string, std::string>::const_iterator it;
    for (it = db.begin(); it != db.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

const std::map<std::string, std::string>& BitcoinExchange::getBtcRates() const {
    return _btcRates;
}

const std::map<std::string, std::string>& BitcoinExchange::getUserInput() const {
    return _userInput;
}

const char* BitcoinExchange::InvalidInputException::what() const throw() {
    return "Invalid input format or data";
}

