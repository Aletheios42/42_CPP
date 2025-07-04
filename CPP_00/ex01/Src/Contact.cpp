#include "../Inc/Contact.hpp"

Contact::Contact() 
    : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(const std::string firstName, const std::string lastName, const std::string nickname,
                 const std::string phoneNumber, const std::string darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

Contact::~Contact() {}


std::string	Contact::getFirstName()const{return (this->firstName);}
std::string	Contact::getLastName()const{return (this->lastName);}
std::string	Contact::getNickname()const{return (this->nickname);}
std::string	Contact::getPhoneNumber()const{return (this->phoneNumber);}
std::string	Contact::getDarkestSecret()const{return (this->darkestSecret);}

