/**
 * @file IPAddress.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief Class to store ip addresses and to offer socket to access them
 */

#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include "../header/OutputStream.h"

class IPAddress {
public:
    IPAddress();
    IPAddress(int* aIp);
    IPAddress(std::string sIp);
    IPAddress(const IPAddress& orig);
    virtual ~IPAddress();
    std::string ipToString();
    uint getOktet(uint okt); //1-4 from right to leaft
    void setOktet(uint okt, uint value); 
private:
    int *ip;
    int error;
};

#endif /* IPADDRESS_H */

