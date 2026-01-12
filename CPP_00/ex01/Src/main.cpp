#include "../Inc/header.h"

int main(int ac, char **av) {

    (void)ac,
    (void)av;
    std::string read_prompt;
    PhoneBook phonebook;

    while (42) {
        std::cout << FIRST_PROMP << std::endl;
        if (!(std::cin >> read_prompt)) { // EOF en el menú principal
            std::cout << "saliendo" << std::endl;
            break;
        }

        if (read_prompt.compare("ADD") == 0)
            phonebook.add_contact();
        else if (read_prompt.compare("SEARCH") == 0)
            phonebook.search_contact();
        else if (read_prompt.compare("EXIT") == 0)
            return(0);
        else
            std::cout << "No valid Command" << std::endl;
    }
    return 0;
}

