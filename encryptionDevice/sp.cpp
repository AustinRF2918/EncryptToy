#include <vector>
#include <iostream>
#include "numericUtilities.hpp"

std::vector<bool> sBox(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, bool r);
std::vector<bool> pBox(std::vector<bool> &matrix, std::vector<int> pos, bool r);
std::vector<bool> iterateBoxes(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, std::vector<int> pos, int it, bool r);
std::string encryptString(std::string ins, std::string code);
std::string decryptString(std::string ins, std::string code);

int main()
{
    std::string s;
    std::cout << "Enter string to encrypt." << std::endl;
    std::cin >> s;

    std::cout << encryptString(s, "aaa");
    std::cout << std::endl;



}

std::string encryptString(std::string ins, std::string code)
{
    conversionDevice conversionObject;
    std::vector<bool> matrix1;
    std::vector<bool> matrix2;
    char prevLetter = 0;
    std::string str;
    std::string str2;
    str = ins;

    for (int i = 0; i < str.size(); i++)
    {
        matrix1.clear();
        matrix2.clear();
        conversionObject.convertFromLetter((str[i] + prevLetter) % 64 + 64, matrix1, matrix2);

        matrix1 = iterateBoxes(matrix1, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 0);
        matrix2 = iterateBoxes(matrix2, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 0);



        str2.push_back(conversionObject.convertToLetter(matrix1, matrix2));
        prevLetter = (str2.back() % 4 + str[1] % str2.back());

    }

    return str2;
}

std::string decryptString(std::string ins, std::string code)
{
    conversionDevice conversionObject;
    std::vector<bool> matrix1;
    std::vector<bool> matrix2;
    std::string str;
    std::string str2;
    str = ins;

    for (int i = 0; i < str.size(); i++)
    {
        matrix1.clear();
        matrix2.clear();
        conversionObject.convertFromLetter(str[i], matrix1, matrix2);

        matrix1 = iterateBoxes(matrix1, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 1);
        matrix2 = iterateBoxes(matrix2, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 1);



        str2.push_back(conversionObject.convertToLetter(matrix1, matrix2));

    }

    return str2;
}


std::vector<bool> iterateBoxes(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, std::vector<int> pos, int it, bool r)
{
    for (int i = 0; i < it; i++)
    {
        matrix = sBox(matrix, tm1, tm2, r);
        matrix = pBox(matrix, pos, r);
    }

    return matrix;
}

std::vector<bool> sBox(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, bool r)
{
    conversionDevice conversionObject;
   if (r == false)
   {
       int s = conversionObject.convertToInteger(matrix);
       for (int i = 0; i < tm1.size(); i++)
       {
            if (s == tm1[i])
            {
                return conversionObject.convertToMatrix(tm2[i]);
            }
       }
       return conversionObject.convertToMatrix(tm1[0]);
   }
   else if (r == true)
   {

       int s = conversionObject.reverseConvertToInteger(matrix);
       for (int i = 7; i != -1; i--)
       {
            if (s == tm2[i])
            {
                return conversionObject.reverseConvertToMatrix(tm1[i]);
            }
       }
       return conversionObject.convertToMatrix(tm1[0]);
   }
}

std::vector<bool> pBox(std::vector<bool> &matrix, std::vector<int> pos, bool r)
{
    if (r == false)
    {
        std::vector<bool> temp = matrix;

        for (int i = 0; i < matrix.size(); i++)
        {
            temp[i] = matrix[pos[i]];
        }

        return temp;
    }
    else if (r == true)
    {
        std::vector<bool> temp = matrix;

        for (int i = 7; i != -1; i--)
        {
            matrix[i] = temp[pos[i]];
        }

        return matrix;
    }
}
