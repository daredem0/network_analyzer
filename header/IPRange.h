/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPRange.h
 * Author: Florian Leuze
 *
 * Created on 12. Februar 2019, 20:43
 */

#ifndef IPRANGE_H
#define IPRANGE_H
#include "../header/IPAddress.h"

using namespace std;

class IPRange {
public:
    IPRange();
    IPRange(const IPRange& orig);
    virtual ~IPRange();
    int* getIp();
    void generateList();
private:
    int ip[8];
    IPAddress *first;
    IPAddress *last;
    std::vector<IPAddress> rangeList;
};

#endif /* IPRANGE_H */

