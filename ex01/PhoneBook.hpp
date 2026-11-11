#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    bool isContactExist(int index);

public:
    PhoneBook();
    bool addContact(Contact &new_contact);
    Contact searchContactByIndex(int index);
    int getContactCount() const;
};

#endif