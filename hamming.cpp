#include <iostream>
#include <vector>
#include <string>

std::string outputParity(std::string bits);
std::string outputHamming(std::string bits);


int main(int argc, char *argv[])
{


    return 0;
}

std::string outputParity(std::string bits)
{
    if (bits.length() != 7)
        return "BAD";

    bool flag = false;

    for (auto i : bits)
    {
        if (i == '0')
            flag = !flag;
    }

    if (flag == 0)
    {
        return (bits + '0');
    }
    else if (flag == 1)
    {
        return (bits + '1');
    }

    return "BAD";
}

std::string outputHamming(std::string bits)
{
    if (bits.length() != 4)
        return "BAD";

    bool flagOne = false;
    bool flagTwo = false;
    bool flagThree = false;
    std::vector <std::vector<bool> > xorMatrix;
    xorMatrix.push_back(std::vector<bool>{0, 1, 1})
    xorMatrix.push_back(std::vector<bool>{1, 0, 1})
    xorMatrix.push_back(std::vector<bool>{1, 1, 0})
    xorMatrix.push_back(std::vector<bool>{0, 0, 0})




    return "BAD";
}
