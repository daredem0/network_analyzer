/**
 * @file Data.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 11.02.2019
 * @brief Data storage. Propably not used in final release
 */

#ifndef DATA_H
#define DATA_H
#include "../header/Network.h"

class Data {
public:
    Network *ip;
    Data();
    Data(const Data& orig);
    virtual ~Data();
    void setIPRange(std::string firstIP, std::string lastIP);
private:
};

#endif /* DATA_H */

