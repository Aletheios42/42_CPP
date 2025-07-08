#include "../Inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : _name(name),_grade(grade) {
    std::cout << "Default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
    : _name(bureaucrat._name),_grade(bureaucrat._grade) {
    std::cout << "Default constructor was called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
    if (this != &bureaucrat) {
        _name = bureaucrat._name;
        _grade = bureaucrat._grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {
    std::cout << "Default Destructor was called" << std::endl;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("exception: grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("exception: grade is too low");
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (stream);
}
