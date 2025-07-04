#ifndef CONTACT_HPP
#define CONTACT_HPP


#include <iostream>
#include <cctype>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        Contact(const std::string firstName, const std::string lastName, const std::string nickname, const std::string phoneNumber, const std::string darkestSecret);
        ~Contact();

        //métodos para obtener datos
        std::string getFirstName(void)const;
        std::string getLastName(void)const;
        std::string getNickname(void)const;
        std::string getPhoneNumber(void)const;
        std::string getDarkestSecret(void)const;
};

#endif
