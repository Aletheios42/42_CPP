#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int execute(const std::string& expr);
    bool isValidExpression(const std::string& expr);

private:
    std::stack<int> _stack;

    void applyOperator(char op);
};

#endif
