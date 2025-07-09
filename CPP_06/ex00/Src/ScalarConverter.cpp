#include "../Inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& s) {
    if (s.length() == 1 && !isdigit(s[0]))
        return TYPE_CHAR;

    // Check special literals: nan, +inf, -inf, nanf, +inff, -inff
    if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf" ||
        s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
        return TYPE_SPECIAL;

    char* endptr;

    // Check int
    errno = 0;
    long val = strtol(s.c_str(), &endptr, 10);
    if (*endptr == '\0' && errno == 0 && val <= INT_MAX && val >= INT_MIN)
        return TYPE_INT;

    // Check float (must end with 'f')
    if (s[s.length()-1] == 'f') {
        errno = 0;
        float fval = strtof(s.c_str(), &endptr);
        if (*(endptr) == 'f' && *(endptr+1) == '\0' && errno == 0)
            return TYPE_FLOAT;
    }

    // Check double
    errno = 0;
    double dval = strtod(s.c_str(), &endptr);
    if (*endptr == '\0' && errno == 0)
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

void ScalarConverter::parseChar(const std::string& s) {
    char c = s[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::parseInt(const std::string& s) {
    char* endptr;
    errno = 0;
    long val = strtol(s.c_str(), &endptr, 10);
    if (errno != 0 || *endptr != '\0' || val > INT_MAX || val < INT_MIN) {
        std::cerr << "Invalid int literal\n";
        return;
    }
    int i = static_cast<int>(val);

    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::parseFloat(const std::string& s) {
    // Remove trailing 'f'
    std::string trimmed = s.substr(0, s.length() - 1);
    char* endptr;
    errno = 0;
    float f = strtof(trimmed.c_str(), &endptr);
    if (errno != 0 || *endptr != '\0') {
        std::cerr << "Invalid float literal\n";
        return;
    }

    if (f >= 32 && f <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::parseDouble(const std::string& s) {
    char* endptr;
    errno = 0;
    double d = strtod(s.c_str(), &endptr);
    if (errno != 0 || *endptr != '\0') {
        std::cerr << "Invalid double literal\n";
        return;
    }

    if (d >= 32 && d <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::parseSpecial(const std::string& s) {
    if (s == "nan" || s == "nanf")
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
    else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff")
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
    else if (s == "-inf" || s == "-inff")
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
    else
        std::cerr << "Invalid special literal\n";
}

void ScalarConverter::convert(const std::string& input) {
    switch (detectType(input)) {
        case TYPE_CHAR:    parseChar(input); break;
        case TYPE_INT:     parseInt(input); break;
        case TYPE_FLOAT:   parseFloat(input); break;
        case TYPE_DOUBLE:  parseDouble(input); break;
        case TYPE_SPECIAL: parseSpecial(input); break;
        case TYPE_INVALID:
        default:           std::cerr << "Invalid literal\n";
    }
}

