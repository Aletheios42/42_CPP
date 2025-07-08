#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _to_sign;
    const int _to_execute;

public:
    AForm();
    AForm(const std::string& name, int to_sign, int to_execute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();

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

    virtual void execute(Bureaucrat const & executor) const = 0;
    class UnsignedFormException : public std::exception {
        public:
            const char *what() const throw() {
                return "exception: unsigned form, signature required";
            }
    };
};

std::ostream &operator<<(std::ostream &os, AForm const &rhs);
