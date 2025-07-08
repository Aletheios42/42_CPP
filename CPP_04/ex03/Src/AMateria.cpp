#include "../Inc/AMateria.hpp"
#include "../Inc/ICharacter.hpp"  // o la ruta real a ICharacter.hpp

AMateria::AMateria() :_type(0) {
    std::cout << "AMateria Defualt Constructor hass been called" << std::endl;
}

AMateria::AMateria(std::string const & type) :_type(type) {
    std::cout << "AMateria name Constructor hass been called" << std::endl;
}


AMateria::AMateria(AMateria const & materia) :_type(materia._type) {
    std::cout << "AMateria copy Constructor hass been called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria copy Destructor hass been called" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}


void AMateria::use(ICharacter& target) {
    std::cout << "AMateria base use called on " << target.getName() << std::endl;
}
