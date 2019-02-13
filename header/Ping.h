/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ping.h
 * Author: Florian Leuze
 *
 * Created on 12. Februar 2019, 20:30
 */

#ifndef PING_H
#define PING_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "../header/IPAddress.h"
using namespace std;

class Ping {
public:
    Ping(std::vector<std::string> message);
    Ping(std::vector<std::string> message, OutputStream *o);
    Ping(const Ping& orig);
    virtual ~Ping(); 
    void setIP(std::string sIp);
    void setMessage(std::string message);
    void setInNetwork(bool in);
    IPAddress* getIP();
    std::vector<std::string> getFullMessage();
    bool getInNetwork();
    void printPing();
    void printShort();
private:
    IPAddress *ip;
    std::vector<std::string> fullMessage;
    bool inNetwork;
    uint ttl;
    double time;
    uint loss;
    uint bytes;
    uint pTransmit;
    uint pReceive;
    OutputStream *outputStream;
    void initPing();
    size_t length(std::string s);
    double find(std::string source, std::string target); 
    std::string findIP(std::string s);
};

#endif /* PING_H */

