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

#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include "../header/Ping.h"
#include "../header/IPRange.h"

class Network {
public:
    std::vector<Ping> pingResults;
    Network(std::string first, std::string last);
    Network(const Network& orig);
    virtual ~Network();
    int* getIP();
    std::string ipToString(int ip);
    int checkIP();
    int ping();
    int pingAll();
    void printPing();
    std::string firstIP_toString();
    std::string lastIP_toString();
private:
    IPRange *range;
    int error;
    void check();
    const int trials = 1;
    const int time = 1;
    //std::vector<std::string> fullPingResults;
    //std::vector<std::string> sPingResults;
};

#endif /* NETWORK_H */

