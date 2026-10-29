#include <iostream>
#include <string>
#include <cstdlib> 
#include <limits>
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


int main() {
    std::string selected_option;
    Contact contact;
    PhoneBook *phoneBook = new PhoneBook();
    while (1)  {
        clearConsole();
        std::cout << "Select an option (ADD / SEARCH / EXIT): ";
        std::cin >> selected_option;
        if (selected_option == ADD) {
            contact = promptInput();
            phoneBook->addContact(contact);
            std::cout << "contact_count:" << phoneBook->getContactCount();
        } else if (selected_option == SEARCH) {
            std::cout << "SEARCHING.." << std::endl;
        } else if (selected_option == EXIT) {
            std::cout << "EXITING SOON.." << std::endl;
            return (1);
        } else {
            std::cout << "Invalid selection. Please enter a valid option.";
        }
    }
}