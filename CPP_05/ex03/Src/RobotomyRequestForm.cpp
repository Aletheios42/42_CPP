#include "../Inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    :AForm("DefaultPresidential", 25, 5), _target("Deafualt") {
        std::cout << "Defualt Constructor was called" << std::endl;
    }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
    :AForm("DefaultPresidential", 25, 5), _target(target) {
        std::cout << "Name Constructor was called" << std::endl;
    }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "Copy Constructor was called (RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=
(const RobotomyRequestForm &rhs) {
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor was called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw UnsignedFormException();
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
