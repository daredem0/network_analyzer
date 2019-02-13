/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPAddress.h
 * Author: Florian Leuze
 *
 * Created on 12. Februar 2019, 20:41
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

