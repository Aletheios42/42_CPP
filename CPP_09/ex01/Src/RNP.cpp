#include "../Inc/RNP.hpp"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}


bool RPN::isValidExpression(const std::string& expr) {
    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (std::isdigit(c)) {
            if (c < '0' || c > '9')
                return false;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int RPN::execute(const std::string& expr) {
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && (token == "+" || token == "-" || token == "*" || token == "/")) {
            applyOperator(token[0]);
        } else if (token.size() == 1 && std::isdigit(token[0])) {
            _stack.push(token[0] - '0');
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid expression: stack size != 1");
    return _stack.top();
}

void RPN::applyOperator(char op) {
    if (_stack.size() < 2)
        throw std::runtime_error("Insufficient operands");

    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();

    int res;
    switch (op) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Division by zero");
            res = a / b; 
            break;
        default:
            throw std::runtime_error(std::string("Invalid operator: ") + op);
    }
    _stack.push(res);
}
