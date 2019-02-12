/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPAddress.h
 * Author: Florian Leuze
 * E-Mail: FlorianLeuze@aol.com
 * Universität Stuttgart
 *
 * Created on 8. Februar 2019, 18:44
 */

#ifndef IPADDRESS_H
#define IPADDRESS_H
#include <string>
#include <iostream>

class IPAddress {
public:
    IPAddress(std::string first, std::string last);
    IPAddress(const IPAddress& orig);
    virtual ~IPAddress();
    int* getIP();
    std::string ipToString(int ip);
    int checkIP();
private:
    int ip[8];
    int error;
    void check();
};

#endif /* IPADDRESS_H */

