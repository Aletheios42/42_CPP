#include "../Inc/AForm.hpp"

AForm::AForm()
    : _name("Default"), _signed(false), _to_sign(150), _to_execute(150) {
    std::cout << "Default Constructor was called" << std::endl;
}

AForm::AForm(const std::string& name, int to_sign, int to_execute)
    : _name(name), _signed(false), _to_sign(to_sign), _to_execute(to_execute) {
    std::cout << "Parametrized Constructor was called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed),
      _to_sign(other._to_sign), _to_execute(other._to_execute) {
    std::cout << "Copy Constructor was called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "Destructor was called" << std::endl;
}


std::string AForm::getName()const {
	return _name;
}

bool AForm::getSigned()const {
	return _signed;
}

int AForm::getSignGrade()const {
	return _to_sign;
}

int AForm::getExecGrade()const {
	return _to_execute;
}

void AForm::beSigned(Bureaucrat const &signer) {
	if (signer.getGrade() > this->_to_sign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &os, AForm const &rhs) {
	os << "AForm: " << rhs.getName() << std::endl
	<< "\t Signed: " << rhs.getSigned() << std::endl
	<< "\t Min grade to sign: " << rhs.getSignGrade() << std::endl
	<< "\t Min grade to exec: " << rhs.getExecGrade() << std::endl;
	return(os);
}
