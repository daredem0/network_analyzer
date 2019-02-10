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

IPAddress::IPAddress(std::string first, std::string last) {
    std::string temp;
    for (int i=0; i<4; i++){
        temp = "";
        for(int j = 0; j<4; j++){
            temp += first[(i+j)+(int)i/4];
        }
        firstAddr[i] = std::stoi(temp);
        std::cout << firstAddr[i] << std::endl;
    }
}

IPAddress::IPAddress(const IPAddress& orig) {
}

IPAddress::~IPAddress() {
}

int* IPAddress::getFirstAddr(){
    
}
int* IPAddress::getSecondAddr(){
    
}
