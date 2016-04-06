#include <vector>
#include <iostream>

int convertToInteger(std::vector<bool> matrix);
int reverseConvertToInteger(std::vector<bool> matrix);
std::vector<bool> convertToMatrix(int in);
std::vector<bool> reverseConvertToMatrix(int in);
std::vector<bool> sBox(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, bool r);
std::vector<bool> pBox(std::vector<bool> &matrix, std::vector<int> pos, bool r);
std::vector<bool> iterateBoxes(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, std::vector<int> pos, int it, bool r);
char convertToLetter(std::vector<bool> matrix1, std::vector<bool> matrix2);
void convertFromLetter(char in, std::vector<bool> &matrix1, std::vector<bool> &matrix2);
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
        convertFromLetter((str[i] + prevLetter) % 64 + 64, matrix1, matrix2);

        matrix1 = iterateBoxes(matrix1, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 0);
        matrix2 = iterateBoxes(matrix2, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 0);



        str2.push_back(convertToLetter(matrix1, matrix2));
        prevLetter = (str2.back() % 4 + str[1] % str2.back());

    }

    return str2;
}

std::string decryptString(std::string ins, std::string code)
{
    std::vector<bool> matrix1;
    std::vector<bool> matrix2;
    std::string str;
    std::string str2;
    str = ins;

    for (int i = 0; i < str.size(); i++)
    {
        matrix1.clear();
        matrix2.clear();
        convertFromLetter(str[i], matrix1, matrix2);

        matrix1 = iterateBoxes(matrix1, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 1);
        matrix2 = iterateBoxes(matrix2, {0, 1, 2, 3, 4, 5, 6, 7}, {7, 5, 6, 4, 3, 1, 2}, {1, 2, 0}, 15, 1);



        str2.push_back(convertToLetter(matrix1, matrix2));

    }

    return str2;
}




char convertToLetter(std::vector<bool> matrix1, std::vector<bool> matrix2)
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

void convertFromLetter(char in, std::vector<bool> &matrix1, std::vector<bool> &matrix2)
{
    int row = 0;
    int col = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (in == ( 64 + i*8 + j))
            {
                matrix1 = convertToMatrix(row);
                matrix2 = convertToMatrix(col);

                return;
            }
            col++;
        }
        row++;
        col = 0;
    }

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
   if (r == false)
   {
       int s = convertToInteger(matrix);
       for (int i = 0; i < tm1.size(); i++)
       {
            if (s == tm1[i])
            {
                return convertToMatrix(tm2[i]);
            }
       }
       return convertToMatrix(tm1[0]);
   }
   else if (r == true)
   {

       int s = reverseConvertToInteger(matrix);
       for (int i = 7; i != -1; i--)
       {
            if (s == tm2[i])
            {
                return reverseConvertToMatrix(tm1[i]);
            }
       }
       return convertToMatrix(tm1[0]);
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

std::vector<bool> convertToMatrix(int in)
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

std::vector<bool> reverseConvertToMatrix(int in)
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



int convertToInteger(std::vector<bool> matrix)
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

int reverseConvertToInteger(std::vector<bool> matrix)
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

