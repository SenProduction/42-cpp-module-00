#include <iostream>
#include <string>
#include <cstdlib> 
#include <limits>
#include <sstream> 
#include <iomanip>
#include "PhoneBook.hpp"

#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getValidAlphaWord(const std::string& prompt, const std::string& errorMsg) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Stream error. ";
            continue ;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        bool hasNonAlpha = false;
        for (size_t i = 0; i < input.length(); ++i) {
            if (!std::isalpha(static_cast<unsigned char>(input[i]))) {
                hasNonAlpha = true;
                break ;
            }
        }

        if (hasNonAlpha) {
            std::cout << errorMsg << "\n";
            continue;
        }

        return (input);
    }
}

long getValidNum(const std::string& prompt, const std::string &errorMsg) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Stream error. ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool hasNonDigit = false;
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isdigit(static_cast<unsigned char>(input[i]))) {
                hasNonDigit = true;
                break ;
            }
        }

        if (hasNonDigit) {
            std::cout << errorMsg << "\n";
            continue;
        }

        return (std::strtol(input.c_str(), NULL, 10));
    }
}

std::string getValidNickname(const std::string& prompt, const std::string& errorMsg) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Stream error. ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool hasSpace = false;
        for (size_t i = 0; i < input.length(); i++) {
            if (std::isspace(static_cast<unsigned char>(input[i]))) {
                hasSpace = true;
                break ;
            }
        }
        if (hasSpace) {
            std::cout << errorMsg << "\n";
            continue;
        }

        return (input);
    }
}

std::string getValidSecret(const std::string& prompt, const std::string& errorMsg) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Stream error. ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool hasSpecialSymbol = false;
        for (size_t i = 0; i < input.length(); i++) {
            if (!(std::isspace(static_cast<unsigned char>(input[i])) || std::isalnum(static_cast<unsigned char>(input[i])))) {
                hasSpecialSymbol = true;
                break ;
            }
        }
        if (hasSpecialSymbol) {
            std::cout << errorMsg << "\n";
            continue;
        }

        return (input);
    }
}

int getValidIndex(const std::string& prompt, const std::string& errorMsg) {
    std::string input;
    int num;

    while (true) {
        std::cout << prompt;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Stream error. ";
        }

        std::istringstream iss(input);
        bool containsNonDigit = false;
        if (iss >> num)
            containsNonDigit = true;

        if (!containsNonDigit) {
            std::cout << errorMsg << std::endl;
            continue ;
        }

        return (num);
    }
}

Contact promptInput() {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    int phone_number;
    std::string darkest_secret;

    first_name = getValidAlphaWord("Enter your first name (alphabet only): ", "Invalid! Names must contain letters only, no numbers/spaces/symbols.");
    last_name = getValidAlphaWord("Enter your last name (alphabet only): ", "Invalid! Names must contain letters only, no numbers/spaces/symbols.");
    nickname = getValidNickname("Enter your nickname (any characters except space): ", "Invalid! Nickname must contain no spaces.");
    phone_number = getValidNum("Enter your phone number (digits only): ", "Invalid! Phone number must contain digits only, no letters/spaces/symbols.");
    darkest_secret = getValidSecret("Enter your darkest secret: ", "Invalid!");
    
    clearConsole();
    std::cout << "\nContact registration successful!\n";
    std::cout << "Created contact details: \n";
    std::cout << "First name: " << first_name << std::endl; 
    std::cout << "Last name: " << last_name << std::endl; 
    std::cout << "Nickname: " << nickname << std::endl; 
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << "***********" << std::endl;

    Contact tempContact(first_name, last_name, nickname, phone_number, darkest_secret);
    return (tempContact);
}

std::string formatField(std::string field)
{
    if (field.length() > 10)
        field = field.substr(0, 9) + ".";
    return field;
}

void displayContact(int index, std::string first,
                     std::string last, std::string nick)
{
    std::cout << "|"
              << std::right << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;

    std::cout << "|"
              << std::right << std::setw(10) << index
              << "|" << std::setw(10) << formatField(first)
              << "|" << std::setw(10) << formatField(last)
              << "|" << std::setw(10) << formatField(nick)
              << "|" << std::endl;
}

int main() {
    std::string selected_option;
    Contact contact;
    PhoneBook phoneBook;
    while (1)  {
        std::cout << "\n===== PHONEBOOK =====" << std::endl;
        std::cout << "1. ADD" << std::endl;
        std::cout << "2. SEARCH" << std::endl;
        std::cout << "3. EXIT" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> selected_option;
        if (selected_option == "1" || selected_option == ADD) {
            contact = promptInput();
            phoneBook.addContact(contact);
            std::cout << "contact_count:" << phoneBook.getContactCount() << std::endl;
        } else if (selected_option == "2" || selected_option == SEARCH) {
            int index = getValidIndex("Enter index to search from entry (between 0 to 7): ", "Invalid index!");
            contact = phoneBook.searchContactByIndex(index);
            if (!contact.getNickname().empty())
                displayContact(index, contact.getFirstName(), contact.getLastName(), contact.getNickname());
        } else if (selected_option == "3" || selected_option == EXIT) {
            return (0);
        } else {
            std::cout << "Invalid selection. Please enter a valid option.";
        }
    }
    return (0);
}