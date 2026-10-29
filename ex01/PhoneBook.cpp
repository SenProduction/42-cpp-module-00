#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : contactCount(0) {};

bool PhoneBook::isContactExist(int index) {
    if (contacts[index].getNickname().empty())
        return (false);
    return (true);
}

bool PhoneBook::addContact(Contact &new_contact) {
    if (contactCount >= 8) {
        contactCount = contactCount - 8;
    }
    contacts[contactCount] = new_contact;
    contactCount++;
    return (true);
}

Contact PhoneBook::searchContactByIndex(int index) {
    if (index > 7 || index < 0)
    {
        std::cout << "Searched index out of range." << std::endl;
        return (Contact());
    }
    if (isContactExist(index))  {
        return (contacts[index]);
    }
    std::cout << "Contact not found." << std::endl;
    return (Contact());
}

int PhoneBook::getContactCount() const{
    return (contactCount);
}




