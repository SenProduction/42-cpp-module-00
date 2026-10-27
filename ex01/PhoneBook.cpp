#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : contactCount(0) {};

bool PhoneBook::addContact(Contact &new_contact) {
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




