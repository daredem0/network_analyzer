/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPAddress.cpp
 * Author: Florian Leuze
 * E-Mail: FlorianLeuze@aol.com
 * Universität Stuttgart
 *
 * Created on 8. Februar 2019, 18:44
 */

#include "../header/IPAddress.h"

using namespace std;

IPAddress::IPAddress(std::string first, std::string last) {
    error = 0;
    for(int j = 0; j < 8; ++j){
        this->ip[j] = 0;
    }
    std::cout << "initialized decryption of ip addresses" << std::endl;
    std::string temp, temp2;
    int i = 0;
    for(std::string::iterator it = first.begin(); it != first.end(); ++it){
        temp2 = *it; //store the value wher iterator points in a temporary string. No idea why C++ wont accept the comparison of *it with "."
        if (temp2 != "."){ 
            temp += *it; 
        }
        else{
            this->ip[i] = std::stoi(temp);
            ++i;
            temp = "";
        }
    }
    this->ip[i] = std::stoi(temp);
    ++i;
    temp = "";
    
    i = 4;
    for(std::string::iterator it = last.begin(); it != last.end(); ++it){
        temp2 = *it;
        if (temp2 != "."){
            temp += *it;
        }
        else{
            this->ip[i] = std::stoi(temp);
            ++i;
            temp = "";
        }
    }
    this->ip[i] = std::stoi(temp);
    ++i;
    temp = "";
    check();
    if(error == 0)
        cout << "decryption done. Seems all went fine" << endl;
    else
        cout << "something seems off. You might want to check your address" << endl;
}

IPAddress::IPAddress(const IPAddress& orig) {
}

IPAddress::~IPAddress() {
}

int* IPAddress::getIP(){
    return this->ip;
}

std::string IPAddress::ipToString(int ip){
    std::string temp = "";
    switch(ip){
        case 0:
            for(int i = 0; i<4; ++i){
                temp += std::to_string(this->ip[i]);
                if(i<3)
                    temp += ".";
            }
            return temp;
        case 1:
            for(int i = 4; i<8; ++i){
                temp += std::to_string(this->ip[i]);
                if(i<7)
                    temp += ".";
            }
            return temp;
        default:
            return "";
    }
}

int IPAddress::checkIP(){
    switch(error){
        case -2:
            cout << "First address is higher than last address. That doesn't make sense." << endl;
            break;
        case -1:
            cout << "Last octet seems to be zero in either first or last address. Are you sure you want that=" << endl;
            break;
        case 0:
            cout << "No complaints" << endl;
            break;
    }
    return error;
}

void IPAddress::check(){    
    //check last octet
    if(this->ip[3] == 0 || this->ip[7] == 0)
        error = -1;
    
    //check if last address is higher than first address. First compare first octet
    if(this->ip[0] > this->ip[4])
        error = -2;
    else{
        if(this->ip[1] > this->ip[5])
            error = -2;
        else{
            if(this->ip[2] > this->ip[6])
                error = -2;
            else{
                if(this->ip[3] > this->ip[7])
                error = -2;
            }
        }
    }
 }
