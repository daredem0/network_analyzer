/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ping.cpp
 * Author: Florian Leuze
 * 
 * Created on 12. Februar 2019, 20:30
 */

#include "../header/Ping.h"

Ping::Ping(std::vector<std::string> message):fullMessage(message) {
    initPing();
}

Ping::Ping(const Ping& orig) {
}

Ping::~Ping() {
}

void Ping::setIP(std::string sIp){
    ip = new IPAddress(sIp);
}
void Ping::setMessage(std::string message){
    //fullMessage = message;
}

void Ping::setInNetwork(bool in){
    inNetwork = in;
}

IPAddress* Ping::getIP(){
    return ip;
}

std::vector<std::string> Ping::getFullMessage(){
    return fullMessage;
}

bool Ping::getInNetwork(){
    return inNetwork;
}

void Ping::initPing(){
    cout << "ping init initialized" << endl;
    if (fullMessage.empty())
        return;
    std::string message = "";
    for(std::vector<std::string>::iterator it = fullMessage.begin(); it != fullMessage.end(); ++it){
        message += *it;
    }
    message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
    
    ip = new IPAddress(findIP(message));
    ttl = (find(message, "ttl=") == -1) ? 0 : find(message, "ttl=");
    time = ((int)find(message, "time=") == -1) ? 0 : find(message, "time=");
    loss = (find(message, "received, ") == -1) ? 0 : find(message, "received, ");
    bytes = (find(message, "data.") == -1) ? 0 : find(message, "data.");
    pTransmit = (find(message, "ping statistics ---") == -1) ? 0 : find(message, "ping statistics ---");
    pReceive = (find(message, "mitted, ") == -1) ? 0 : find(message, "mitted, ");
    printPing();
}

size_t Ping::length(std::string s){
    return s.length();
}

double Ping::find(std::string source, std::string target){
    int i = source.find(target);
    source.erase(0, i+length(target));
    i = source.find_first_of(" ");
    source.erase(i, source.length());
    if(i = source.find_first_of(".")!= -1)
        source[i] = ',';
    try{
        return stod(source);
    }
    catch(const std::invalid_argument){
        cout << "exception cought" << endl;
        return -1;
    }
}

std::string Ping::findIP(std::string s){
    cout << "initialized find ip" << endl;
    int i = s.find_first_of("-");
    s.erase(0, i+4);
    i = s.find_first_of(" ");
    s.erase(i, s.length());
    return s;
}

void Ping::printPing(){
    cout << "Found IP: " << ip->ipToString() << endl;
    cout << "Found ttl: " << ttl << endl;
    cout << "Found time: " << time << "ms" << endl;
    cout << "Found loss: " << loss << "%" << endl;
    cout << "Found bytes: " << bytes << endl;
    cout << "Found packages tramsitted: " << pTransmit << endl;
    cout << "Found packages received: " << pReceive << endl;
    if(pTransmit != 0 && pReceive == 0){
        inNetwork = false;
        cout << "IP " << ip->ipToString() << " is not a member of the network" << endl;
    }
    else{
        inNetwork = true;
        cout << "IP " << ip->ipToString() << " is a member of the network" << endl;
    }
    
}
