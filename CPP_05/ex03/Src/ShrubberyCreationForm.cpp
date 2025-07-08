#include "../Inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    :AForm("DefaultPresidential", 25, 5), _target("Deafualt") {
        std::cout << "Defualt Constructor was called" << std::endl;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    :AForm("DefaultPresidential", 25, 5), _target(target) {
        std::cout << "Name Constructor was called" << std::endl;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {
    std::cout << "Copy Constructor was called (ShrubberyCreationForm)" << std::endl;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=
(const ShrubberyCreationForm &rhs) {
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor was called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw UnsignedFormException();
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
