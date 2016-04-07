#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <string>
#include <vector>

class encryptionDevice
{
    public:
        std::string encryptString(std::string ins, std::string code);
        std::string decryptString(std::string ins, std::string code);
        std::vector<bool> iterateBoxes(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, std::vector<int> pos, int it, bool r);
        std::vector<bool> sBox(std::vector<bool> &matrix, std::vector<int> tm1, std::vector<int> tm2, bool r);
        std::vector<bool> pBox(std::vector<bool> &matrix, std::vector<int> pos, bool r);
};

#endif
