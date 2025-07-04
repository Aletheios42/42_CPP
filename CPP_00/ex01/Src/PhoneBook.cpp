#include "../Inc/PhoneBook.hpp"

PhoneBook::PhoneBook() : next_index(0), size(0) {}

void PhoneBook::add_contact() {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter first name" << std::endl;
    std::cin >> first_name;
    std::cout << "Enter last name" << std::endl;
    std::cin >> last_name;
    std::cout << "Enter nickname" << std::endl;
    std::cin >> nickname;
    std::cout << "Enter phone number" << std::endl;
    std::cin >> phone_number;
    if (phone_number.length() != 9)
        return;

    for (int i = 0; i < 9; i++) {
        if (phone_number[i] < '0' || phone_number[i] > '9')
            return;
    }

    std::cout << "Enter darkest secret" << std::endl;
    std::cin >> darkest_secret;

    this->contacts[this->next_index] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
    this->next_index = (this->next_index + 1) % 8;
    if (size < 8)
        size++;
}

void PhoneBook::search_contact() {
    for (int i = 0; i < size; i++) {
        std::cout << "--------------------------" << std::endl;
        std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
        std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
        std::cout << "Phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << std::endl;
    }
}

