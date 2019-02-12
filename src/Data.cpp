/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.cpp
 * Author: Florian Leuze
 * 
 * Created on 11. Februar 2019, 23:49
 */

#include "../header/Data.h"

Data::Data() {
}

Data::Data(const Data& orig) {
}

Data::~Data() {
    delete ip;
}

int Data::setIP(std::string firstIP, std::string lastIP){
    this->ip = new IPAddress(firstIP, lastIP);
}

int* Data::getIP(){
    return this->ip->getIP();
}

std::string Data::firstIP_toString(){
    return this->ip->ipToString(0);
}
std::string Data::lastIP_toString(){
    return this->ip->ipToString(1);
}

int Data::checkIP(){
    this->ip->checkIP();
}
