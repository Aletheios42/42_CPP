#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int next_index;
        int size;
    public:
        PhoneBook();
        void add_contact();
        void search_contact();
};

#endif
