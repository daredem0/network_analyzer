/**
 * @file IPAddress.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief IPAddress Class cpp file
 */

#include "../header/IPAddress.h"

IPAddress::IPAddress(){
    error = 0;
    ip = new int[4];
}

IPAddress::IPAddress(int* aIp){
    error = 0;
    ip = new int[4];
    for(int i = 0; i < 4; ++i){
        ip[i] = *(aIp+i);
    }
}

IPAddress::IPAddress(std::string sIp) {
    try{
       error = 0;
       ip = new int[4];
        for(int j = 0; j < 4; ++j){
            ip[j] = 0;
        }
        std::cout << "I got this: " << sIp << std::endl;
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
    catch(...){
        std::cout << "Ecveption while decrypting ip" << std::endl;
    }
    std::cout << "made id through" << std::endl;
    std::cout << "IP address was: " << this->ipToString() << std::endl;
}

IPAddress::IPAddress(const IPAddress& orig) {
    error = 0;
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