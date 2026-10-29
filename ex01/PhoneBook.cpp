#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : contactCount(0) {};

bool PhoneBook::addContact(Contact &new_contact) {
    // std::cout << "contact_count: " << contactCount << std::endl;
    if (contactCount >= 8) {
        contactCount = contactCount - 8;
    }
    contacts[contactCount] = new_contact;
    contactCount++;
    return (true);
}

int PhoneBook::getContactCount() const{
    return (contactCount);
}




