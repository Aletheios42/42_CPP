#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void loadUserInput(const std::string& filename);
    void processData(const std::map<std::string, std::string>& btcRates,
                                  const std::map<std::string, std::string>& userInput);

    void printDatabase(const std::string& title, const std::map<std::string, std::string>& db) const;

    class InvalidInputException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    // Getters para imprimir desde main si quieres
    const std::map<std::string, std::string>& getBtcRates() const;
    const std::map<std::string, std::string>& getUserInput() const;

  private:
    std::map<std::string, std::string> _btcRates;
    std::map<std::string, std::string> _userInput;

    bool parseLine(const std::string& line, char sep, std::string& date, std::string& value) const;
    void validateDate(const std::string& date_str) const;
    void validateValue(const std::string& value_str) const;
    void trim(std::string& s) const;

};

#endif
