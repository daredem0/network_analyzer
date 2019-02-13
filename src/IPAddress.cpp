/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPAddress.cpp
 * Author: Florian Leuze
 * 
 * Created on 12. Februar 2019, 20:41
 */

#include "../header/IPAddress.h"

IPAddress::IPAddress(){
    ip = new int[4];
}

IPAddress::IPAddress(int* aIp){
    ip = new int[4];
    for(int i = 0; i < 4; ++i){
        ip[i] = *(aIp+i);
    }
}

IPAddress::IPAddress(std::string sIp) {
   error = 0;
   ip = new int[4];
    for(int j = 0; j < 8; ++j){
        ip[j] = 0;
    }
    std::cout << "initialized decryption of ip addresses" << std::endl;
    std::string temp, temp2;
    int i = 0;
    for(std::string::iterator it = sIp.begin(); it != sIp.end(); ++it){
        temp2 = *it; //store the value wher iterator points in a temporary string. No idea why C++ wont accept the comparison of *it with "."
        if (temp2 != "."){ 
            temp += *it; 
        }
        else{
            ip[i] = std::stoi(temp);
            ++i;
            temp = "";
        }
    }
    ip[i] = std::stoi(temp);
}

IPAddress::IPAddress(const IPAddress& orig) {
    ip = new int[4];
    for(int i = 0; i<4; ++i){
        ip[i] = orig.ip[i];
    }
}

IPAddress::~IPAddress() {
    delete ip;
}

std::string IPAddress::ipToString(){
    std::string temp = "";
    for(int i = 0; i<4; ++i){
        temp += std::to_string(*(ip+i));
        if(i<3)
            temp += ".";
    }
    return temp;
}

uint IPAddress::getOktet(uint okt){
    okt = 4-okt;
    return *(ip+okt);
}

void IPAddress::setOktet(uint okt, uint value){
    okt = 4-okt;
    ip[okt] = value;
}