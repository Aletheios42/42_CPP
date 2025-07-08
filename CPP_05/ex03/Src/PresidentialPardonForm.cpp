#include "../Inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    :AForm("DefaultPresidential", 25, 5), _target("Deafualt") {
        std::cout << "Defualt Constructor was called" << std::endl;
    }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) 
    :AForm("DefaultPresidential", 25, 5), _target(target) {
        std::cout << "Name Constructor was called" << std::endl;
    }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {
    std::cout << "Copy Constructor was called" << std::endl;
}


PresidentialPardonForm& PresidentialPardonForm::operator=
(const PresidentialPardonForm &rhs) {
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor was called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw UnsignedFormException();
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
