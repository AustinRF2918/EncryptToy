#ifndef NUMERICUTIL_H
#define NUMERICUTIL_H
#include <vector>

//A little bit stupid of a design:
//We should design these as static which I will reimplement in a bit.
class conversionDevice
{
    public:
    std::vector<bool> convertToMatrix(int in);
    std::vector<bool> reverseConvertToMatrix(int in);
    int convertToInteger(std::vector<bool> matrix);
    int reverseConvertToInteger(std::vector<bool> matrix);
    void convertFromLetter(char in, std::vector<bool> &matrix1, std::vector<bool> &matrix2);
    char convertToLetter(std::vector<bool> matrix1, std::vector<bool> matrix2);

};



#endif
