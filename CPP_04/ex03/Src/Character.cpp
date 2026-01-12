#include "../Inc/Character.hpp"
#include "../Inc/AMateria.hpp"

Character::Character() : _name("Character") {
    std::cout << "Character default constructor called\n";
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(std::string name) : _name(name) {
    std::cout << "Character default constructor called\n";
        for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(const Character& other) : ICharacter(other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            _slots[i] = other._slots[i];
        }
    }
    std::cout << "Character copy constructor called\n";
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {

    }
    std::cout << "Character copy assignment operator called\n";
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called\n";
    for (int i = 0; i < 4; i++) {
        delete(this->_slots[i]);
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!_slots[i]) {
            _slots[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        _slots[idx] = NULL;
        delete(this->_slots[idx]);
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _slots[idx]) {
        _slots[idx]->use(target);
    }
}
