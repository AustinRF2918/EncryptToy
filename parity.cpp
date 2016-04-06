#include <iostream>
#include <vector>
#include <string>


int main(int argc, char *argv[])
{
if (argc == 0)
        std::cout << "Please enter a 7 bit sequence.";

    std::string input;

    input = argv[1];

    if (input.length() != 7)
    {
        std::cout << "Bad input" << std::endl;
        return 1;
    }

    bool flag = false;
    for (auto i : input)
    {

        if (i == '0')
            flag = !flag;
        else
            flag = flag;
    }

    for (auto i : input)
    {
        std::cout << i;
    }
    std::cout << flag;



    return 0;
}
