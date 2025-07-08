#include "../Inc/Form.hpp"

Form::Form()
    : _name("Default"), _signed(false), _to_sign(150), _to_execute(150) {
    std::cout << "Default Constructor was called" << std::endl;
}

Form::Form(const std::string& name, int to_sign, int to_execute)
    : _name(name), _signed(false), _to_sign(to_sign), _to_execute(to_execute) {
    std::cout << "Parametrized Constructor was called" << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed),
      _to_sign(other._to_sign), _to_execute(other._to_execute) {
    std::cout << "Copy Constructor was called" << std::endl;
}

Form& Form::operator=(const Form& rhs) {
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Destructor was called" << std::endl;
}


std::string Form::getName()const {
	return _name;
}

bool Form::getSigned()const {
	return _signed;
}

int Form::getSignGrade()const {
	return _to_sign;
}

int Form::getExecGrade()const {
	return _to_execute;
}

void Form::beSigned(Bureaucrat const &signer) {
	if (signer.getGrade() > this->_to_sign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &os, Form const &rhs) {
	os << "Form: " << rhs.getName() << std::endl
	<< "\t Signed: " << rhs.getSigned() << std::endl
	<< "\t Min grade to sign: " << rhs.getSignGrade() << std::endl
	<< "\t Min grade to exec: " << rhs.getExecGrade() << std::endl;
	return(os);
}
