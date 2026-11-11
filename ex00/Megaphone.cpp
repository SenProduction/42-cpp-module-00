#include <iostream>
#include <string>
#include <cctype>

void printUpper(std::string text)
{
    int i = 0;
    char upperCasedChar;
    while (text[i])
    {
        upperCasedChar = std::toupper(static_cast<unsigned char>(text[i]));
        std::cout << upperCasedChar;
        i++;
    }
}

int main(int argc, char* argv[])
{
    int i;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        i = 1;
        while (argv[i])
            printUpper(argv[i++]);
        std::cout << "\n";
    }
    return (0);
}