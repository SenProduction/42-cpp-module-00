#include "Contact.hpp"

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(0), darkest_secret("") {}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, long phone_number, std::string darkest_secret) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const {
    return (first_name);
}

std::string Contact::getLastName() const {
    return (last_name);
}

std::string Contact::getNickname() const {
    return (nickname);
}

long Contact::getPhoneNumber() const {
    return (phone_number);
}

void Contact::setFirstName(std::string first_name) {
    this->first_name = first_name;
}

void Contact::setLastName(std::string last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(std::string nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(long phone_number) {
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}