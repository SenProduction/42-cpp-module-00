#ifndef CONTACT_HPP
#define CONTACT_HPP

#pragma once

class Contact {
private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    long phone_number;
    std::string darkest_secret;

public:
    Contact(void);
    Contact(int index, std::string first_name, std::string last_name, std::string nickname, long phone_number, std::string darkest_secret);
    int getIndex(void);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string nickname(void);
    long getPhoneNumber(void);
    std::string getDarkestSecret(void);


    void setIndex(int index);
    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickname(std::string nickname);
    void setPhoneNumber(long phone_number);
    void setDarkestSecret(std::string darkest_secret);
};

#endif