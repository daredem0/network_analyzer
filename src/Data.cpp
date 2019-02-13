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

void Data::setIPRange(std::string firstIP, std::string lastIP){
    this->ip = new Network(firstIP, lastIP);
}