#include <iomanip>
#include "Validator.hpp"
#include "PhoneBook.hpp"

#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

std::string formatField(std::string field)
{
    if (field.length() > 10)
        field = field.substr(0, 9) + ".";
    return field;
}

void renderMainDisplay() {
    std::cout << "\n===== PHONEBOOK =====" << std::endl;
        std::cout << "1. ADD" << std::endl;
        std::cout << "2. SEARCH" << std::endl;
        std::cout << "3. EXIT" << std::endl;
        std::cout << "Select an option: ";
}

void renderContact(int index, std::string first,
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
    darkest_secret = getValidSecret("Enter your darkest secret: ");
    
    clearConsole();
    std::cout << "\nContact registration successful!\n";
    std::cout << "Created contact details: \n";
    std::cout << "First name: " << first_name << std::endl; 
    std::cout << "Last name: " << last_name << std::endl; 
    std::cout << "Nickname: " << nickname << std::endl; 
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;

    return (Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

int main() {
    std::string selected_option;
    Contact contact;
    PhoneBook phoneBook;
    while (1)  {
        renderMainDisplay();
        
        if (!(std::cin >> selected_option))
        {
            if (std::cin.eof())
                std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            else
                std::cerr << "Input error!\n";
            break;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (selected_option == "1" || selected_option == ADD) {
            contact = promptInput();
            phoneBook.addContact(contact);
        } else if (selected_option == "2" || selected_option == SEARCH) {
            int index = getValidIndex("Enter index to search from entry (between 0 to 7): ", "Invalid index!");
            contact = phoneBook.searchContactByIndex(index);
            if (!contact.getNickname().empty())
                renderContact(index, contact.getFirstName(), contact.getLastName(), contact.getNickname());
        } else if (selected_option == "3" || selected_option == EXIT) {
            return (0);
        } else {
            std::cout << "Invalid selection. Please enter a valid option.";
        }
    }
    return (0);
}