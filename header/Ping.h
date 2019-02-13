/**
 * @file Ping.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief Class to store extract information from a ping result and store those in a useful manner
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

