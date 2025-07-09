#pragma once

#include <iostream>
#include <string>
#include <cstdlib>   // strtol, strtof, strtod
#include <cerrno>    // errno
#include <climits>   // LONG_MIN, LONG_MAX

class ScalarConverter {

    private:
        enum LiteralType {
            TYPE_CHAR,
            TYPE_INT,
            TYPE_FLOAT,
            TYPE_DOUBLE,
            TYPE_SPECIAL,
            TYPE_INVALID
        };

        static LiteralType detectType(const std::string& s);
        static void parseChar(const std::string& s);
        static void parseInt(const std::string& s);
        static void parseFloat(const std::string& s);
        static void parseDouble(const std::string& s);
        static void parseSpecial(const std::string& s);

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();

        static void convert(const std::string& parameter);
};

