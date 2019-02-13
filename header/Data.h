/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.h
 * Author: Florian Leuze
 *
 * Created on 11. Februar 2019, 23:49
 */

#ifndef DATA_H
#define DATA_H
#include "../header/Network.h"

class Data {
public:
    Network *ip;
    Data();
    Data(const Data& orig);
    virtual ~Data();
    void setIPRange(std::string firstIP, std::string lastIP);
};

#endif /* DATA_H */

