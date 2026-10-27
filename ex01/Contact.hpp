#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

#pragma once

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    long phone_number;
    std::string darkest_secret;

public:
    Contact();
    Contact(std::string first_name, std::string last_name, std::string nickname, long phone_number, std::string darkest_secret);
    
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    long getPhoneNumber() const;

    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickname(std::string nickname);
    void setPhoneNumber(long phone_number);
    void setDarkestSecret(std::string darkest_secret);
};

#endif