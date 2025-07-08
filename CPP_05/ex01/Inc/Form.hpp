#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _to_sign;
    const int _to_execute;

public:
    Form();
    Form(const std::string& name, int to_sign, int to_execute);
    Form(const Form& other);
    Form& operator=(const Form& rhs);
    ~Form();

    class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw() {
                return ("exception: grade is too high");
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw() {
                return ("exception: grade is too low");
            }
    };

    std::string getName()const;
    bool getSigned()const;
    int getSignGrade()const;
    int getExecGrade()const;

    void beSigned(Bureaucrat const &signer);
};

std::ostream &operator<<(std::ostream &os, Form const &rhs);
