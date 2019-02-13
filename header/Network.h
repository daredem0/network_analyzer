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
#include <gtk/gtk.h>
#include <thread>
#include <sstream>
#include "../header/Ping.h"
#include "../header/IPRange.h"

using namespace std;

class Network {
public:
    std::vector<Ping> pingResults;
    Network();
    Network(std::string first, std::string last);
    Network(const Network& orig);
    virtual ~Network();
    int* getIP();
    std::string ipToString(int ip);
    int checkIP();
    int ping();
    int ping(std::string ip);
    int pingAll();
    void printPing();
    void pingShortRes();
    std::string firstIP_toString();
    std::string lastIP_toString();
    bool threadActive();
    void threadKill();
    void reserveList(size_t n);
    std::thread *thPing, *org;
private:
    void pingWorker(void *data, void *list);
    void threadActiveWorker(void *data, void *ptr);
    IPRange *range;
    int error;
    void check();
    const int trials = 1;
    const int time = 1;
    OutputStream *outputStream;
    //std::vector<std::string> fullPingResults;
    //std::vector<std::string> sPingResults;
};

#endif /* NETWORK_H */

