#include <vector>
#include "numericUtilities.hpp"

void conversionDevice::convertFromLetter(char in, std::vector<bool> &matrix1, std::vector<bool> &matrix2)
{
    conversionDevice conversionObject;
    int row = 0;
    int col = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (in == ( 64 + i*8 + j))
            {
                matrix1 = conversionObject.convertToMatrix(row);
                matrix2 = conversionObject.convertToMatrix(col);

                return;
            }
            col++;
        }
        row++;
        col = 0;
    }

}

char conversionDevice::convertToLetter(std::vector<bool> matrix1, std::vector<bool> matrix2)
{
    int i = convertToInteger(matrix1);
    int j = convertToInteger(matrix2);
    const int asciiUCOffset = 64;
    char ret;

    /*
        A B C D E F G H
        I J K L M N O P
        Q R S T U V W X
        Y Z a b c d e f
        g h i j k l m n
        o p q r s t u v
        w x y z 0 1 2 3
        4 5 6 7 8 9 . ,
    */
    // A Z ascii range 65 90

    ret = asciiUCOffset + (i*8) + j;
    return ret;
}



std::vector<bool> conversionDevice::convertToMatrix(int in)
{
    if (in == 0)
        return {0, 0, 0};
    else if (in == 1)
        return {0, 0, 1};
    else if (in == 2)
        return {0, 1, 0};
    else if (in == 3)
        return {0, 1, 1};
    else if (in == 4)
        return {1, 0, 0};
    else if (in == 5)
        return {1, 0, 1};
    else if (in == 6)
        return {1, 1, 0};
    else
        return {1, 1, 1};
}

std::vector<bool> conversionDevice::reverseConvertToMatrix(int in)
{
    if (in == 7)
        return {0, 0, 0};
    else if (in == 6)
        return {0, 0, 1};
    else if (in == 5)
        return {0, 1, 0};
    else if (in == 4)
        return {0, 1, 1};
    else if (in == 3)
        return {1, 0, 0};
    else if (in == 2)
        return {1, 0, 1};
    else if (in == 1)
        return {1, 1, 0};
    else
        return {1, 1, 1};
}



int conversionDevice::convertToInteger(std::vector<bool> matrix)
{
    if (matrix[0] == 0)
    {
        if (matrix[1] == 0)
        {
            if (matrix[2] == 0)
            {
                return 0;
            }
            else if (matrix[2] == 1)
            {
                return 1;
            }
        }
        else if (matrix[1] == 1)
        {
            if (matrix[2] == 0)
            {
                return 2;
            }
            else if (matrix[2] == 1)
            {
                return 3;
            }

        }

    }
    else if (matrix[0] == 1)
    {
        if (matrix[1] == 0)
        {
            if (matrix[2] == 0)
            {
                return 4;
            }
            else if (matrix[2] == 1)
            {
                return 5;
            }

        }
        else if (matrix[1] == 1)
        {
            if (matrix[2] == 0)
            {
                return 6;
            }
            else if (matrix[2] == 1)
            {
                return 7;
            }

        }
    }

}

int conversionDevice::reverseConvertToInteger(std::vector<bool> matrix)
{
    if (matrix[0] == 0)
    {
        if (matrix[1] == 0)
        {
            if (matrix[2] == 0)
            {
                return 7;
            }
            else if (matrix[2] == 1)
            {
                return 6;
            }
        }
        else if (matrix[1] == 1)
        {
            if (matrix[2] == 0)
            {
                return 5;
            }
            else if (matrix[2] == 1)
            {
                return 4;
            }

        }

    }
    else if (matrix[0] == 1)
    {
        if (matrix[1] == 0)
        {
            if (matrix[2] == 0)
            {
                return 3;
            }
            else if (matrix[2] == 1)
            {
                return 2;
            }

        }
        else if (matrix[1] == 1)
        {
            if (matrix[2] == 0)
            {
                return 1;
            }
            else if (matrix[2] == 1)
            {
                return 0;
            }

        }
    }

}

