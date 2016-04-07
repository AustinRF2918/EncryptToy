#include <vector>
#include <iostream>
#include "numericUtilities.hpp"
#include "encryptionUtilities.hpp"

int main()
{
    std::string s;
    std::cout << "Enter string to encrypt." << std::endl;
    std::cin >> s;

    encryptionDevice encrypter;
    std::cout << encrypter.encryptString(s, "aaa");
    std::cout << std::endl;
    return 0;
}
