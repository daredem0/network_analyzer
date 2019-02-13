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

Ping::Ping(std::vector<std::string> message, OutputStream *o):fullMessage(message),outputStream(o){
    initPing();
}

Ping::Ping(std::vector<std::string> message):fullMessage(message){
    initPing();
    outputStream = new OutputStream();
}

Ping::Ping(const Ping& orig) {
    ip = new IPAddress(orig.ip->ipToString());
    inNetwork = orig.inNetwork;
    ttl = orig.ttl;
    time = orig.time;
    loss = orig.loss;
    bytes = orig.bytes;
    pTransmit = orig.pTransmit;
    pReceive = orig.pReceive;
    outputStream = new OutputStream();
    *outputStream = *orig.outputStream;
    fullMessage = orig.fullMessage;
}

Ping::~Ping() {
    delete ip;
    fullMessage.clear();
    //delete outputStream;
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
    pTransmit = (find(message, "statistics ---") == -1) ? 0 : find(message, "statistics ---");
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
        cout << "exception cought with target: " << target << endl;
        cout << "message was: " << source << endl;
        return -1;
    }
}

std::string Ping::findIP(std::string s){
    cout << "initialized find ip" << endl;
    int i = s.find_first_of("-");
    s.erase(0, i+4);
    i = s.find_first_of(" ");
    s.erase(i, s.length());
    cout << "You made it through: " << s << endl;
    return s;
}

void Ping::printPing(){
    ostringstream buffer;
    cout << "Found IP: " << ip->ipToString() << endl;
    cout << "Found ttl: " << ttl << endl;
    cout << "Found time: " << time << "ms" << endl;
    cout << "Found loss: " << loss << "%" << endl;
    cout << "Found bytes: " << bytes << endl;
    cout << "Found packages tramsitted: " << pTransmit << endl;
    cout << "Found packages received: " << pReceive << endl;;
    OutputStream stream;
    //stream.writeOutput(buffer.str());
    if(pTransmit != 0 && pReceive == 0){
        inNetwork = false;
        cout << "IP " << ip->ipToString() << " is not a member of the network" << endl;
    }
    else{
        inNetwork = true;
        cout << "IP " << ip->ipToString() << " is a member of the network" << endl;
    }
    //stream.writeOutput(buffer.str());
}

void Ping::printShort(){
    //cout << "in print" << endl;
    if(this->inNetwork)
        cout << "IP Address: " << ip->ipToString() << " is reachable." << endl;
    else
        cout << "IP Address: " << ip->ipToString() << " is unreachable." << endl;
}

/*void Ping::printPing(){
    ostringstream buffer;
    buffer << "Found IP: " << ip->ipToString() << endl
            << "Found ttl: " << ttl << endl
            << "Found time: " << time << "ms" << endl
            << "Found loss: " << loss << "%" << endl
            << "Found bytes: " << bytes << endl
            << "Found packages tramsitted: " << pTransmit << endl
            << "Found packages received: " << pReceive << endl;
    OutputStream stream;
    stream.writeOutput(buffer.str());
    if(pTransmit != 0 && pReceive == 0){
        inNetwork = false;
        buffer << "IP " << ip->ipToString() << " is not a member of the network" << endl;
    }
    else{
        inNetwork = true;
        buffer << "IP " << ip->ipToString() << " is a member of the network" << endl;
    }
    stream.writeOutput(buffer.str());
}*/
