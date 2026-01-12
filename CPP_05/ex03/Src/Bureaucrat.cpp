#include "../Inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    std::cout << "Default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : _name(name),_grade(grade) {
     if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    std::cout << "Name constructor was called" << std::endl;
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

void Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

void Bureaucrat::setName(const std::string &name) {
    _name = name;
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

void Bureaucrat::signForm(AForm &toSign) {
	try
	{
		toSign.beSigned(*this);
		std::cout << this->_name << " signed " << toSign.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << toSign.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << this->_name << " couldn't exec " << form.getName() << " because " << e.what() << std::endl;
	}
}
