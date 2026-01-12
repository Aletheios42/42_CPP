#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs) {
        this->_db = rhs._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (std::string::npos == first) return str;
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (leap ? 29 : 28)) return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) {
    char* end;
    value = std::strtof(valueStr.c_str(), &end);

    if (valueStr == "" || *end != 0) {
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t delim = line.find(',');
        if (delim == std::string::npos) continue;

        std::string date = trim(line.substr(0, delim));
        std::string valStr = trim(line.substr(delim + 1));
        
        _db[date] = std::strtof(valStr.c_str(), NULL);
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, delim));
        std::string valStr = trim(line.substr(delim + 1));
        float value = 0.0f;

       
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        
        if (!isValidValue(valStr, value)) {
            continue; 
        }

        std::map<std::string, float>::iterator it = _db.upper_bound(date);
        
        if (it == _db.begin()) {
            std::cout << "Error: no data for this date." << std::endl;
        } else {
            --it; 
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        }
    }
    file.close();
}