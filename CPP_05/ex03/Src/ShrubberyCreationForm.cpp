#include "../Inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    :AForm("DefaultPresidential", 145, 137), _target("Deafualt") {
        std::cout << "Defualt Constructor was called" << std::endl;
    }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    :AForm("DefaultPresidential", 145, 137), _target(target) {
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
	
    
    std::string fileName = this->_target + "_shrubbery";
    
    std::ofstream outfile(fileName.c_str());

    if (outfile.is_open())
    {
        outfile << "         v" << std::endl;
        outfile << "        >X<" << std::endl;
        outfile << "         A" << std::endl;
        outfile << "        d$b" << std::endl;
        outfile << "      .d\\$$b." << std::endl;
        outfile << "    .d$i$$\\$$b." << std::endl;
        outfile << "       d$$@b" << std::endl;
        outfile << "      d\\$$$ib" << std::endl;
        outfile << "    .d$$$\\$$$b" << std::endl;
        outfile << "  .d$$@$$$$\\$$ib." << std::endl;
        outfile << "      d$$i$$b" << std::endl;
        outfile << "     d\\$$$$@$b" << std::endl;
        outfile << "  .d$@$$\\$$$$$@b." << std::endl;
        outfile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
        outfile << "        ###" << std::endl;
        outfile << "        ###" << std::endl;
        outfile << "        ###" << std::endl;
        
        outfile.close();
    }
    else
    {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
}
