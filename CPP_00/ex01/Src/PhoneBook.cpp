#include "../Inc/PhoneBook.hpp"
#include <limits>
#include <iomanip> 
#include <iostream>


PhoneBook::PhoneBook() : next_index(0), size(0) {}
void PhoneBook::add_contact() {
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    std::cout << "Enter first name:" << std::endl;
    if (!(std::cin >> first_name)) {
        std::cout << "cancelando ADD\n";
        return;
    }

    std::cout << "Enter last name:" << std::endl;
    if (!(std::cin >> last_name)) {
        std::cout << "cancelando ADD\n";
        return;
    }

    std::cout << "Enter nickname:" << std::endl;
    if (!(std::cin >> nickname)) {
        std::cout << "cancelando ADD\n";
        return;
    }

    std::cout << "Enter phone number:" << std::endl;
    if (!(std::cin >> phone_number)) {
        std::cout << "cancelando ADD\n";
        return;
    }
    if (phone_number.length() != 9) {
        std::cout << "Bad Length" << std::endl;
        return;
    }
    for (int i = 0; i < 9; i++) {
        if (phone_number[i] < '0' || phone_number[i] > '9') {
            std::cout << "Bad Syntax" << std::endl;
            return;
        }
    }

    std::cout << "Enter darkest secret:" << std::endl;
    if (!(std::cin >> darkest_secret)) {
        std::cout << "cancelando ADD\n";
        return;
    }

    this->contacts[this->next_index] =
        Contact(first_name, last_name, nickname, phone_number, darkest_secret);
    this->next_index = (this->next_index + 1) % 8;
    if (size < 8)
        size++;
}


void PhoneBook::search_contact() {
    if (size == 0) {
        std::cout << "No contacts saved.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << std::setw(10) << i << "|";

        std::string field = contacts[i].getFirstName();
        if (field.length() > 10)
            std::cout << field.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << field;
        std::cout << "|";

        field = contacts[i].getLastName();
        if (field.length() > 10)
            std::cout << field.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << field;
        std::cout << "|";

        field = contacts[i].getNickname();
        if (field.length() > 10)
            std::cout << field.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << field;

        std::cout << std::endl;
    }

    int idx;
    std::cout << "Enter index of contact to display: ";
    if (!(std::cin >> idx)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.\n";
        return;
    }

    if (idx < 0 || idx >= size) {
        std::cout << "Index out of range.\n";
        return;
    }

    std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}