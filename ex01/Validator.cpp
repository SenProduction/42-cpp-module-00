#include "Validator.hpp"

std::string getValidAlphaWord(const std::string& prompt, const std::string& errorMsg) {
    std::string input;

    while (true) {
        std::cout << prompt;

        if (!std::getline(std::cin, input)) {
            if (std::cin.eof())
                return ("");
            std::cin.clear();
            std::cout << "Stream error. ";
            continue ;
        }

        bool hasNonAlpha = false;
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isalpha(static_cast<unsigned char>(input[i]))
                && input[i] != ' ') {
                hasNonAlpha = true;
                break ;
            }
        }

        if (hasNonAlpha) {
            std::cout << errorMsg << "\n";
            continue ;
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

        if (!std::getline(std::cin, input)) {
            if (std::cin.eof())
                return ("");
            std::cin.clear();
            std::cout << "Stream error. ";
            continue ;
        }

        bool hasNonAlpha = false;
        for (size_t i = 0; i < input.length(); i++) {
            if (std::isspace(static_cast<unsigned char>(input[i]))) {
                hasNonAlpha = true;
                break ;
            }
        }

        if (hasNonAlpha) {
            std::cout << errorMsg << "\n";
            continue ;
        }
        
        return (input);
    }
}

std::string getValidSecret(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;

        if (!std::getline(std::cin, input)) {
            if (std::cin.eof())
                return ("");
            std::cin.clear();
            std::cout << "Stream error. ";
            continue ;
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
            if (!std::cin.eof())
                std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Stream error. ";
            return (-1);
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