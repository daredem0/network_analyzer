/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPRange.cpp
 * Author: Florian Leuze
 * 
 * Created on 12. Februar 2019, 20:43
 */

#include "../header/IPRange.h"

IPRange::IPRange() {
}

IPRange::IPRange(const IPRange& orig) {
}

IPRange::~IPRange() {
}

int* IPRange::getIp(){
    return ip;
}

//not working yet. Segfault. Propably some problem with getOKtet or setOktet
void IPRange::generateList(){
    first = new IPAddress(ip);
    cout << "First address: " <<first->ipToString() << endl;
    last = new IPAddress(ip+4);
    cout << "Last address: " <<last->ipToString() << endl;
    rangeList.push_back(*first);
    std::vector<IPAddress>::iterator it = rangeList.begin()+1;
    cout << (*(it-1)).getOktet(1) << endl;
    cout << last->getOktet(1) << endl;
    for(it; (*(it-1)).getOktet(1) < last->getOktet(1); ++it){
        IPAddress *ipTemp = new IPAddress();
        cout << "in loop" << endl;
        cout << (*(it-1)).getOktet(1) << endl;
        cout << (*(it-1)).getOktet(2) << endl;
        cout << (*(it-1)).getOktet(3) << endl;
        cout << (*(it-1)).getOktet(4) << endl;
        ipTemp->setOktet(1, ((*(it-1)).getOktet(1))+1);
        ipTemp->setOktet(2, (*(it-1)).getOktet(2));
        ipTemp->setOktet(3, (*(it-1)).getOktet(3));
        ipTemp->setOktet(4, (*(it-1)).getOktet(4));
        cout << "Generated IP: " << ipTemp->ipToString() << endl;
        cout << "Generated IP: " << ipTemp->getOktet(1) << ipTemp->getOktet(2) << ipTemp->getOktet(3) << ipTemp->getOktet(4)<< endl;
        cout << "Generated IP: " << (it-1)->getOktet(1) << (it-1)->getOktet(2) << (it-1)->getOktet(3) << (it-1)->getOktet(4)<< endl;
        rangeList.push_back(*ipTemp);
        cout << (*(it-1)).getOktet(1) << endl;
        cout << "size" << rangeList.size() << endl;
        delete ipTemp;
    }
    cout << "now running through vector " << endl;
    for(std::vector<IPAddress>::iterator it2 = rangeList.begin(); it2 < rangeList.end(); ++it2){
        std::cout << (*it2).ipToString() << std::endl;
    }
}


