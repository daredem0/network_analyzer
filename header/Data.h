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
#include "../header/IPAddress.h"

class Data {
public:
    Data();
    Data(const Data& orig);
    virtual ~Data();
    int setIP(std::string firstIP, std::string lastIP);
    int *getIP();
    std::string firstIP_toString();
    std::string lastIP_toString();
    int checkIP();
private:
    IPAddress *ip;
};

#endif /* DATA_H */

