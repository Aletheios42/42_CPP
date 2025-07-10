#include "../Inc/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    try {
        btc.loadDatabase("data.csv");
        btc.loadUserInput(argv[1]);

        btc.processData(btc.getBtcRates(), btc.getUserInput());
    } catch (const BitcoinExchange::InvalidInputException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

